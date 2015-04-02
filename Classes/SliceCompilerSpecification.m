// **********************************************************************
//
// Copyright (c) 2008-2015 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

//
// This is used by the headers to figure out which Xcode plugin API to use,
// we force it to 4.6.
//
#define XCODE_VERSION 46

#import <SliceCompilerSpecification.h>
#import <XCPBuildSystem.h>
#import <XCPDependencyGraph.h>
#import <XCPSupport.h>
#import <Foundation/NSException.h>

@interface XCDependencyGraphCreationContext : NSObject
{
    PBXTargetBuildContext *_buildContext;
}
- (void)addNodeToClean:(id)node;
@end

@interface XCMacroExpansionScope : NSObject
{
    PBXTargetBuildContext *_buildContext;
    PBXTargetBuildContext *_cachedBuildContext;
    id _cachedSdk;
}
@property(readonly) PBXTargetBuildContext *buildContext;
-(id) dependencyGraphCreationContext;
@end

@interface PBXTargetBuildContext(IceBuilder)
-(XCDependencyNode*) dependencyNodeForPath:(NSString*)path;
-(XCDependencyCommand*) createCommandWithRuleInfo:(NSArray*)info commandPath:(NSString*)path arguments:(NSArray*)args
                                          forNode:(XCDependencyNode*)node toolSpecification:(id)arg5
                          withMacroExpansionScope:(XCMacroExpansionScope*)arg6;
@end

@interface XCCompilerSpecification(IceBuilder)
-(NSArray*) commandLineForAutogeneratedOptionsWithMacroExpansionScope:(XCMacroExpansionScope*)scope;
@end

@interface SliceCompilerConfiguration : NSObject
{
@private
    NSString* translator;
    NSString* shlibpath;
    NSString* slicedir;
    BOOL cpp;
    NSString* error;
    BOOL sdk;
    BOOL linkWithServices;
}

@property (readonly) NSString* translator;
@property (readonly) NSString* shlibpath;
@property (readonly) NSString* slicedir;
@property (readonly) NSString* icehome;
@property (readonly) BOOL cpp;
@property (readonly) BOOL sdk;
@property (readonly) BOOL linkWithServices;
@property (readonly) NSString* error;

-(id)initWithContext:(PBXTargetBuildContext*)context;

@end

@implementation SliceCompilerConfiguration

@synthesize translator;
@synthesize shlibpath;
@synthesize slicedir;
@synthesize icehome;
@synthesize cpp;
@synthesize sdk;
@synthesize error;
@synthesize linkWithServices;

-(id)initWithContext:(PBXTargetBuildContext*)context
{
    if(!(self = [super init]))
    {
        return nil;
    }

    NSFileManager* fileManager = [NSFileManager defaultManager];
    [fileManager changeCurrentDirectoryPath:context.baseDirectoryPath];
    NSString* sliceIceHome = [context expandedValueForString:@"$(SLICE_ICE_HOME)"];
    if(sliceIceHome.length > 0)
    {
        sdk = NO;
        BOOL dir = NO;
        if(![fileManager fileExistsAtPath:sliceIceHome isDirectory:&dir] || !dir)
        {
            error = [NSString stringWithFormat:@"Ice installation cannot be found: \"%@\"", sliceIceHome];
            return self;
        }

        slicedir = [sliceIceHome stringByAppendingPathComponent:@"share/slice"];
        if(![fileManager fileExistsAtPath:slicedir isDirectory:&dir] || !dir)
        {
            slicedir = [sliceIceHome stringByAppendingPathComponent:@"slice"];
            if(![fileManager fileExistsAtPath:slicedir isDirectory:&dir] || !dir)
            {
                error = [NSString stringWithFormat:@"Slice files cannot be found: \"%@\"", slicedir];
                return self;
            }
        }

        //
        // Is this a development tree, as opposed to an install? If so the bin and lib directories
        // are in cpp, not at the root.
        //
        NSString* homeCpp = [sliceIceHome stringByAppendingPathComponent:@"cpp"];
        if([fileManager fileExistsAtPath:homeCpp isDirectory:&dir] && dir)
        {
            sliceIceHome = homeCpp;
        }

        cpp = [[context expandedValueForString:@"$(SLICE_CPP_FLAG)"] isEqualToString:@"YES"];

        NSString* exe = (cpp ? @"slice2cpp" : @"slice2objc");
        translator = [[sliceIceHome stringByAppendingPathComponent:@"bin"] stringByAppendingPathComponent:exe];

        NSDictionary* env = [[NSProcessInfo processInfo] environment];
        NSString* libdir = [sliceIceHome stringByAppendingPathComponent:@"lib"];
        shlibpath = [env objectForKey:@"DYLD_LIBRARY_PATH"];
        if(shlibpath)
        {
            shlibpath = [shlibpath stringByAppendingPathComponent:libdir];
        }
        else
        {
            shlibpath = libdir;
        }

        icehome = sliceIceHome;
    }
    else
    {
        NSString* sdksRaw = [context expandedValueForString:@"$(ADDITIONAL_SDKS)"];
        NSArray* sdks = [sdksRaw componentsSeparatedByString:@" "];
        BOOL found = NO;
        for(__strong NSString* sdkDir in sdks)
        {
            if([sdkDir rangeOfString:@"SDKs"].location == NSNotFound)
            {
                continue;
            }

            sdkDir = [sdkDir stringByDeletingLastPathComponent];
            if([sdkDir rangeOfString:@"Cpp"].location != NSNotFound)
            {
                translator = [sdkDir stringByAppendingPathComponent:@"bin/slice2cpp"];
                if(![fileManager isExecutableFileAtPath:translator])
                {
                    continue;
                }
                cpp = YES;
            }
            else if([sdkDir rangeOfString:@"ObjC"].location != NSNotFound)
            {
                translator = [sdkDir stringByAppendingPathComponent:@"bin/slice2objc"];
                if(![fileManager isExecutableFileAtPath:translator])
                {
                    continue;
                }
                cpp = NO;
            }
            else
            {
                continue;
            }

            sdk = YES;
            found = YES;

            // The bin and slice directories exist at the root of the SDK.
            slicedir = [sdkDir stringByAppendingPathComponent:@"slice"];

            BOOL dir = NO;
            if(![fileManager fileExistsAtPath:slicedir isDirectory:&dir] || !dir)
            {
                error = [NSString stringWithFormat:@"Slice files cannot be found: \"%@\"", slicedir];
                return self;
            }
            break;
        }

        if(!found)
        {
            error = [NSString stringWithFormat:@"Ice Touch SDK cannot be found: \"%@\"", sdksRaw];
            return self;
        }
    }

    //
    // Are we compiling with the libc++ library?
    //
    if([[context expandedValueForString:@"$(CLANG_CXX_LIBRARY)"] isEqualToString:@"libstdc++"])
    {
        error = @"Ice Touch doesn't support libstdc++";
        return self;
    }

    //
    // Do we want to link service client libraries?
    //
    linkWithServices = [[context expandedValueForString:@"$(SLICE_LINK_WITH_SERVICES)"] isEqualToString:@"YES"];
    return self;
}

-(NSString*)description
{
    return [NSString stringWithFormat:@"translator=%@ shlibpath=%@ slicedir=%@ cpp=%d",
            translator, shlibpath, slicedir, cpp];
}
@end


typedef struct Configuration Configuration;

@interface XMLSliceParserDelegate : NSObject<NSXMLParserDelegate>
{
@private

    NSMutableArray* depends;
}

@property(nonatomic, readonly) NSArray* depends;

-(void) parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI
    qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict;
@end

@implementation XMLSliceParserDelegate

@synthesize depends;

-(id) init
{
    if(![super init])
    {
        return nil;
    }
    depends = [[NSMutableArray alloc] init];
    return self;
}

-(void) parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI
    qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict
{
    if([elementName isEqualToString:@"dependsOn"])
    {
        NSString* name = [attributeDict objectForKey:@"name"];
        if(name != 0)
        {
            [depends addObject:name];
        }
    }
}

@end

@implementation SliceCompilerSpecification

// Run the slice compiler with --depend-xml to determine the dependencies for the given slice file.
-(NSArray*)dependenciesForSliceFile:(NSString*)path
               inTargetBuildContext:(PBXTargetBuildContext*)context
            withMacroExpansionScope:(XCMacroExpansionScope*)scope
{
    NSMutableDictionary* env = [[[NSProcessInfo processInfo] environment] mutableCopy];
    SliceCompilerConfiguration* conf = [[SliceCompilerConfiguration alloc] initWithContext:context];
    if(conf.error)
    {
        [context addDependencyAnalysisErrorMessageFormat:@"%@", conf.error];
        return [NSArray array];
    }

    if(conf.shlibpath)
    {
        [env setObject:conf.shlibpath forKey:@"DYLD_LIBRARY_PATH"];
    }

    NSTask *dependTask = [[NSTask alloc] init];
    NSMutableArray *args = [NSMutableArray array];

    [dependTask setLaunchPath:conf.translator];
    [dependTask setEnvironment:env];
    [dependTask setCurrentDirectoryPath:[context baseDirectoryPath]];

    NSPipe* newPipe = [NSPipe pipe];
    NSFileHandle* readHandle = [newPipe fileHandleForReading];
    NSData* inData = nil;

    // write handle is closed to this process
    [dependTask setStandardOutput:newPipe];
    // Stderr goes no-where.
    //[dependTask setStandardError:newPipe];

    /* set arguments */
    if(scope)
    {
        [args addObjectsFromArray:[self commandLineForAutogeneratedOptionsWithMacroExpansionScope:scope]];
    }
    else
    {
        [args addObjectsFromArray:[self commandLineForAutogeneratedOptionsInTargetBuildContext:context]];
    }
    [args addObjectsFromArray:[[context expandedValueForString:@"$(build_file_compiler_flags)"]
                                  arrayByParsingAsStringList]];
    [args addObject:[NSString stringWithFormat:@"-I%@", conf.slicedir]];

    // Use old style dependency parsing?
    if(conf.cpp)
    {
        [args addObject:@"--depend"];
    }
    else
    {
        [args addObject:@"--depend-xml"];
    }

    //
    // Always add --ice when parsing dependencies, this avoid
    // errors when try to parse dependencies for Ice Slice files.
    //
    BOOL found = NO;
    NSString* item;
    for(item in args)
    {
        if([item rangeOfString:@"--ice"].location != NSNotFound)
        {
            found = YES;
            break;
        }
    }

    if(!found)
    {
        [args addObject:@"--ice"];
    }

    [args addObject:path];

    //NSLog(@"args: %@", args);

    [dependTask setArguments:args];

    @try
    {
        [dependTask launch];
    }
    @catch(NSException* ex)
    {
        NSLog(@"translator not accessible");
        return [NSArray array];
    }

    NSMutableData* output = [[NSMutableData alloc] init];
    while((inData = [readHandle availableData]) && [inData length])
    {
        [output appendData:inData];
    }

    // Don't use NSTask waitUntilExit, this is for some reasons
    // causing crashes with Xcode.
    int wait = 500; // Wait 5 seconds.
    while([dependTask isRunning] && wait > 0)
    {
        [NSThread sleepForTimeInterval:0.01];
        --wait;
    }

    if([dependTask terminationStatus] != 0)
    {
        NSLog(@"translator exited with non-zero status %d", [dependTask terminationStatus]);
        return [NSArray array];
    }

    if(conf.cpp)
    {
        NSMutableArray* dep = [NSMutableArray array];
        NSString* soutput = [[NSString alloc]initWithData:output encoding:NSUTF8StringEncoding];
        // Parse C++ style dependencies.
        NSArray* lines = [soutput componentsSeparatedByString:@"\n"];
        // Ignore the first two lines.
        if(lines.count > 2)
        {
            NSEnumerator *e = [lines objectEnumerator];
            [e nextObject]; // Foo.cpp
            [e nextObject]; // Foo.ice
            // The remaning lines are the slice dependencies themselves.
            NSString* line;
            while((line = [e nextObject]))
            {
                // Strip the trailing \ if any.
                if([line characterAtIndex:line.length-1] == '\\')
                {
                    line = [line substringToIndex:line.length-1];
                }
                // Strip leading and trailing whitespace
                line = [line stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
                // Don't add empty dependencies.
                if(line.length > 0)
                {
                    [dep addObject:line];
                }
            }
        }
        return dep;
    }
    else
    {
        // Parse XML style dependencies.
        XMLSliceParserDelegate* del = [[XMLSliceParserDelegate alloc] init];
        NSXMLParser* parser = [[NSXMLParser alloc] initWithData:output];
        [parser setDelegate:del];
        BOOL success = [parser parse];
        if(!success)
        {
            NSLog(@"XML parse of dependencies failed\n%@", output);
            return [NSArray array];
        }
        return [del depends];
    }
}

-(NSArray*) computeDependenciesForFilePath:(NSString*)input
                                    ofType:(PBXFileType*)type
                           outputDirectory:(NSString*)outputDir
                   withMacroExpansionScope:(XCMacroExpansionScope*)scope
{
    return [self computeDependenciesForFilePath:input
                                         ofType:type
                                outputDirectory:outputDir
                           inTargetBuildContext:scope.buildContext
                        withMacroExpansionScope:scope];
}

// Called by Xcode 4
-(NSArray*) computeDependenciesForFilePath:(NSString*)input
                                    ofType:(PBXFileType*)type
                           outputDirectory:(NSString*)outputDir
                      inTargetBuildContext:(PBXTargetBuildContext*)context
{
    return [self computeDependenciesForFilePath:input
                                         ofType:type
                                outputDirectory:outputDir
                           inTargetBuildContext:context
                        withMacroExpansionScope:nil];
}

-(NSArray*) computeDependenciesForFilePath:(NSString*)input
                                    ofType:(PBXFileType*)type
                           outputDirectory:(NSString*)outputDir
                      inTargetBuildContext:(PBXTargetBuildContext*)context
                   withMacroExpansionScope:(XCMacroExpansionScope*)scope
{
    // compute input path (for variable substitution)
    input = [context expandedValueForString:input];

    SliceCompilerConfiguration* conf = [[SliceCompilerConfiguration alloc] initWithContext:context];
    if(conf.error)
    {
        [context addDependencyAnalysisErrorMessageFormat:@"%@", conf.error];
        return [NSArray array];
    }

    // The output file goes in the derived files dir.
    NSString* generatedOutputDir = [context expandedValueForString:@"$(SLICE_OUTPUT_DIR)"];
    NSString* outputBase = [generatedOutputDir stringByAppendingPathComponent:[[input lastPathComponent]
                                                                               stringByDeletingPathExtension]];
    NSString* sourceExtension = (conf.cpp) ? @"cpp" : @"m";
    NSString* sourceOutput = [outputBase stringByAppendingPathExtension:sourceExtension];
    NSString* headerOutput = [outputBase stringByAppendingPathExtension:@"h"];

    // create dependency nodes
    XCDependencyNode* outputSourceNode;
    XCDependencyNode* outputHeaderNode;
    XCDependencyNode* inputNode;
    if(scope)
    {
        outputSourceNode = [context dependencyNodeForPath:sourceOutput];
        outputHeaderNode = [context dependencyNodeForPath:headerOutput];
        inputNode = [context dependencyNodeForPath:input];

        [[scope dependencyGraphCreationContext] addNodeToClean:outputSourceNode];
        [[scope dependencyGraphCreationContext] addNodeToClean:outputHeaderNode];
    }
    else
    {
        outputSourceNode = [context dependencyNodeForName:sourceOutput createIfNeeded:YES];
        outputHeaderNode = [context dependencyNodeForName:headerOutput createIfNeeded:YES];
        inputNode = [context dependencyNodeForName:input createIfNeeded:YES];
    }

    // Add dependencies
    NSEnumerator *e = [[self dependenciesForSliceFile:input
                                 inTargetBuildContext:context
                              withMacroExpansionScope:scope] objectEnumerator];
    NSString *filename;
    while((filename = [e nextObject]))
    {
        NSString *filepath = [context absolutePathForPath:filename];
        XCDependencyNode *node;
        if(scope)
        {
            node = [context dependencyNodeForPath:filepath];
        }
        else
        {
            node = [context dependencyNodeForName:filepath createIfNeeded:YES];
        }
        [node setDontCareIfExists:YES];
        [inputNode addIncludedNode:node];
    }

    // Create slice2objc command
    XCDependencyCommand* dep;
    if(scope)
    {
        dep = [context createCommandWithRuleInfo:[NSArray arrayWithObjects:(conf.cpp ? @"slice2cpp" : @"slice2objc"),
                                                          [context naturalPathForPath:input],nil]
                                     commandPath:conf.translator
                                       arguments:nil
                                         forNode:outputHeaderNode
                               toolSpecification:self
                         withMacroExpansionScope:scope];
        [dep addArgumentsFromArray:[self commandLineForAutogeneratedOptionsWithMacroExpansionScope:scope]];
    }
    else
    {
        dep = [context createCommandWithRuleInfo:[NSArray arrayWithObjects:(conf.cpp ? @"slice2cpp" : @"slice2objc"),
                                                          [context naturalPathForPath:input],nil]
                                     commandPath:conf.translator
                                       arguments:nil
                                         forNode:outputHeaderNode];
        [dep setToolSpecification:self]; // So Xcode knows how to parse the output, etc.
        [dep addArgumentsFromArray:[self commandLineForAutogeneratedOptionsInTargetBuildContext:context]];
    }

    [dep addOutputNode:outputSourceNode];
    [dep addArgumentsFromArray:[[context expandedValueForString:@"$(build_file_compiler_flags)"]
                                arrayByParsingAsStringList]];

    [dep addArgument:[NSString stringWithFormat:@"-I%@", conf.slicedir]];
    [dep addArgument:input];
    [dep setPhaseNumber:3]; // This is the phase that the yacc plugin uses.

    if(conf.shlibpath)
    {
        [dep addEnvironmentValue:conf.shlibpath forKey:@"DYLD_LIBRARY_PATH"];
    }

    // Create dependency rules. The source and the header depend on the input file.
    [outputSourceNode addDependedNode:inputNode];
    [outputHeaderNode addDependedNode:inputNode];

    // Add the source & headder output to the generated source files.
    [context addPath:sourceOutput toFilePathListWithIdentifier:@"GeneratedSourceFiles"];
    [context addPath:headerOutput toFilePathListWithIdentifier:@"GeneratedSourceFiles"];

    //
    // Add linker options (unless this is a static library project).
    //
    if(![[context expandedValueForString:@"$(MACH_O_TYPE)"] isEqualToString:@"staticlib"])
    {
        NSMutableArray* options;
        if([[context expandedValueForString:@"$(PLATFORM_NAME)"] isEqualToString:@"macosx"])
        {
            options = [NSMutableArray arrayWithObjects:@"-liconv", @"-lbz2", nil];
        }
        else
        {
            options = [NSMutableArray array];
        }

        if(!conf.sdk)
        {
            if(conf.cpp)
            {
                [options addObject:@"-lIceUtil"];
                [options addObject:@"-lIce"];
            }
            else
            {
                [options addObject:@"-ObjC"];
                [options addObject:@"-lIceObjC"];
            }

            if(conf.linkWithServices)
            {
                if(conf.cpp)
                {
                    [options addObject:@"-lGlacier2"];
                    [options addObject:@"-lIceStorm"];
                    [options addObject:@"-lIceGrid"];
                }
                else
                {
                    [options addObject:@"-lGlacier2ObjC"];
                    [options addObject:@"-lIceStormObjC"];
                    [options addObject:@"-lIceGridObjC"];
                }
            }
        }
        else
        {
            if(conf.cpp)
            {
                [options addObject:@"-lIce"];
                if(conf.linkWithServices)
                {
                    [options addObject:@"-lGlacier2"];
                    [options addObject:@"-lIceStorm"];
                    [options addObject:@"-lIceGrid"];
                }
            }
            else
            {
                [options addObject:@"-ObjC"];
                [options addObject:@"-lc++"];
                [options addObject:@"-lIceObjC"];
                if(conf.linkWithServices)
                {
                    [options addObject:@"-lGlacier2ObjC"];
                    [options addObject:@"-lIceStormObjC"];
                    [options addObject:@"-lIceGridObjC"];
                }
            }
        }

        [context addCompilerRequestedLinkerParameters:
                   [NSDictionary dictionaryWithObject:options forKey:@"AdditionalCommandLineArguments"]];
    }

    if(!conf.sdk && !scope)
    {
        NSArray* current;

        NSString* includeDir = [conf.icehome stringByAppendingPathComponent:@"include"];
        current = [[context expandedValueForString:@"$(HEADER_SEARCH_PATHS)"] arrayByParsingAsStringList];
        if(![current containsObject:includeDir])
        {
            NSMutableArray* copy = [current mutableCopy];
            [copy addObject:includeDir];
            [context setStringValue:[copy componentsJoinedByString:@" "] forDynamicSetting:@"HEADER_SEARCH_PATHS"];
        }

        NSString* libDir = [conf.icehome stringByAppendingPathComponent:@"lib"];
        current = [[context expandedValueForString:@"$(LIBRARY_SEARCH_PATHS)"] arrayByParsingAsStringList];
        if(![current containsObject:libDir])
        {
            NSMutableArray* copy = [current mutableCopy];
            [copy addObject:libDir];
            [context setStringValue:[copy componentsJoinedByString:@" "] forDynamicSetting:@"LIBRARY_SEARCH_PATHS"];
        }
    }

    // The output of the plugin is a single source node.
    return [NSArray arrayWithObject:outputSourceNode];
}
@end
