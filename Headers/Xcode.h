//
// Generated using class-dump 3.5 (64 bit) and Xcode SDK Version 6.3
//

#import <Foundation/Foundation.h>

@interface PBXBuildContext : NSObject
{
}

- (id)absoluteExpandedPathForString:(id)arg1;
- (id)dictionaryByExpandingEntriesInDictionary:(id)arg1;
- (id)arrayByExpandingEntriesInArray:(id)arg1;
- (BOOL)expandedBooleanValueForString:(id)arg1;
- (BOOL)expandedValueIsNonEmptyForString:(id)arg1;
- (id)expandedValueForString:(id)arg1;
- (void)setPropertyExpansionContext:(id)arg1;
- (id)propertyExpansionContext;
- (void)setLowestTierBuildSettingsDictionaries:(id)arg1;
- (void)setDefaultsTierBuildSettingsDictionaries:(id)arg1;
- (void)popDefaultsTierBuildSettingsDictionary;
- (void)pushDefaultsTierBuildSettingsDictionary:(id)arg1;
- (void)setCustomTierBuildSettingsDictionaries:(id)arg1;
- (void)popCustomTierBuildSettingsDictionary;
- (void)pushCustomTierBuildSettingsDictionary:(id)arg1;
- (void)setHighestTierBuildSettingsDictionaries:(id)arg1;
- (void)setToolParameterTierBuildSettingsDictionaries:(id)arg1;
- (void)popToolParameterTierBuildSettingsDictionary;
- (void)pushToolParameterTierBuildSettingsDictionary:(id)arg1;
- (void)removeAllDynamicSettings;
- (void)appendStringOrStringListValue:(id)arg1 toDynamicSetting:(id)arg2;
- (void)prependStringOrStringListValue:(id)arg1 toDynamicSetting:(id)arg2;
- (void)removeDynamicSetting:(id)arg1;
- (void)setStringValue:(id)arg1 forDynamicSetting:(id)arg2;
- (void)setBaseDirectoryPath:(id)arg1;
- (id)baseDirectoryPath;
- (void)setCurrentBuildOperation:(id)arg1;
- (id)currentBuildOperation;
- (void)dealloc;
- (id)init;
- (id)valueForUndefinedKey:(id)arg1;
@end

@interface PBXTargetBuildContext : PBXBuildContext
{

}

+ (id)headerFileExtensionsForHeadermaps;
+ (id)identifierForTraditionalHeadermap;
+ (id)identifierForHeadermapWithAllHeadersInProject;
+ (id)identifierForHeadermapWithAllProductHeadersInProject;
+ (id)identifierForHeadermapWithProductHeaders;
+ (id)identifierForHeadermapWithGeneratedFiles;
+ (id)identifierForHeadermapWithBreadthFirstRecursiveContentsAtPath:(id)arg1;
+ (void)initialize;
+ (id)sharedDependencyGraphEventProcessingInvocationQueue;
+ (void)_setupThreadTraceName;
- (void)_2009_enqueueCommandsOntoWorkQueue:(id)arg1 startingAtNode:(id)arg2;
- (id)nodesMatchingPattern:(id)arg1;
@property(readonly, copy) NSString *description;
- (id)debugOutputLog;
- (void)finishLoggingDebugOutput;
- (void)startLoggingDebugOutputIfAppropriate;
- (BOOL)writeToGraphVizFileAtPath:(id)arg1;
- (void)_makeNodesSetBuildInfoIfNeeded;
- (void)_addNodeThatNeedsToSetBuildInfo:(id)arg1;
- (void)enqueueAllOutOfDateCommandsOntoWorkQueue:(id)arg1;
- (void)enqueueOutOfDateCommandsOntoWorkQueue:(id)arg1 startingAtNode:(id)arg2;
- (void)checkWaitCountsOfAllDependencyNodes;
- (void)analyzeAllProductDependencies;
- (void)analyzeDependenciesForFilePaths:(id)arg1;
- (void)analyzeDependenciesForNodes:(id)arg1;
- (void)resetStatesOfAllDependencyNodes;
- (void)addProductNode:(id)arg1;
- (id)productNodes;
- (BOOL)writeAuxiliaryFilesForBuildOperation:(id)arg1 buildLogRecorder:(id)arg2;
- (id)importedFilesForPath:(id)arg1;
- (id)importedFilesForPath:(id)arg1 ensureFilesExist:(BOOL)arg2;
- (id)_XCOQ_searchContext;
- (BOOL)shouldScanHeadersOfFileAtPath:(id)arg1;
- (id)makeSymlinkToFileAtPath:(id)arg1 atPath:(id)arg2;
- (id)moveFileAtPath:(id)arg1 toPath:(id)arg2;
- (id)dittoFileAtPath:(id)arg1 toPath:(id)arg2;
- (id)copyFileAtPath:(id)arg1 toPath:(id)arg2;
- (id)touchFileAtPath:(id)arg1;
- (id)createDirectoryAtPath:(id)arg1;
- (id)buildDirectoryPath;
- (void)removeAllBuildMessages;
- (void)removeAllUncategorizedBuildMessages;
- (void)addUncategorizedBuildMessage:(id)arg1;
- (id)uncategorizedBuildMessages;
- (void)removeAllLinkerBuildMessages;
- (void)addLinkerBuildMessage:(id)arg1;
- (id)linkerBuildMessages;
- (void)removeAllBuildMessagesForFileAtPath:(id)arg1;
- (void)addBuildMessage:(id)arg1 forFileAtPath:(id)arg2;
- (id)buildMessagesForFileAtPath:(id)arg1;
- (id)writeDependencyInfoCacheToBuildDirectory:(id)arg1 createIfNecessary:(BOOL)arg2;
- (id)readDependencyInfoCacheFromBuildDirectory:(id)arg1;
- (id)buildStateStore;
- (id)dependencyInfoCache;
- (id)dependencyInfoCacheFilename;
- (void)clearCompiledFileInfoForAllFiles;
- (void)clearCompiledFileInfoForFileAtPath:(id)arg1;
- (id)buildInfoForFileAtPath:(id)arg1;
- (void)postBuildInfoNotificationIfNeeded;
- (void)noteBuildInfoDidChange:(id)arg1;
- (id)buildInfoForEntityIdentifier:(id)arg1 createIfNeeded:(BOOL)arg2;
- (BOOL)isFileUpToDateAtPath:(id)arg1;
- (id)searchPathsForRez;
- (id)effectiveRezSearchPaths;
- (id)effectiveLibrarySearchPaths;
- (id)effectiveFrameworkSearchPaths;
- (id)effectiveUserHeaderSearchPaths;
- (id)effectiveHeaderSearchPaths;
- (id)_effectiveSearchPathsForSearchPathBuildSetting:(id)arg1;
- (id)effectiveSearchPathsForSearchPath:(id)arg1;
- (void)generateHeadermapFiles;
- (void)setHeadermapToolInvocation:(id)arg1 forFilePath:(id)arg2;
- (void)setHeadermap:(id)arg1 forIdentifier:(id)arg2;
- (id)headermapForIdentifier:(id)arg1;
- (void)addDerivedFileCache:(id)arg1;
- (void)pruneDerivedFileCaches;
- (id)disassembledFilePathForSourceFilePath:(id)arg1;
- (id)preprocessedFilePathForSourceFilePath:(id)arg1;
- (id)constantFlagsForBuildToolWithIdentifier:(id)arg1;
- (unsigned long long)countForBuildFileBaseName:(id)arg1;
- (void)countBuildFileBaseName:(id)arg1;
- (id)sourceFilePathForCompiledFilePath:(id)arg1;
- (id)compiledFilePathForSourceFilePath:(id)arg1;
- (id)buildFileRefForPath:(id)arg1;
- (id)filePathListWithIdentifier:(id)arg1;
- (void)addPath:(id)arg1 toFilePathListWithIdentifier:(id)arg2;
- (BOOL)effectiveSDKPackageIsCompatibleWithCommandLineTool:(id)arg1 forFileAtPath:(id)arg2;
- (void)checkDeploymentTargetAgainstSDKForCommandLineTool:(id)arg1;
- (void)setConstantFlags:(id)arg1 forBuildToolWithIdentifier:(id)arg2;
- (void)setCompiledFilePath:(id)arg1 forSourceFilePath:(id)arg2;
- (void)defineSymlinkContents:(id)arg1 forAuxiliarySymlinkAtPath:(id)arg2;
- (id)symlinkContentsForAuxiliarySymlinkAtPath:(id)arg1;
- (void)defineFileContents:(id)arg1 forAuxiliaryFileAtPath:(id)arg2;
- (id)fileContentsForAuxiliaryFileAtPath:(id)arg1;
- (void)defineFileContents:(id)arg1 forAuxiliaryFileAtPath:(id)arg2 withPosixPermissions:(unsigned long long)arg3;
- (void)addDependencyAnalysisBuildOnlyWarningMessageFormat:(id)arg1;
- (void)addDependencyAnalysisWarningMessageFormat:(id)arg1;
- (void)addDependencyAnalysisBuildOnlyErrorMessageFormat:(id)arg1;
- (void)addDependencyAnalysisErrorMessageFormat:(NSString*)format,...;
- (void)_addDependencyAnalysisMessageString:(id)arg1;
- (unsigned long long)numberOfDependencyAnalysisWarnings;
- (unsigned long long)numberOfDependencyAnalysisErrors;
- (void)removeAllBuildSetupMessageStrings;
- (id)dependencyAnalysisMessageStrings;
- (void)cancelDependencyGraphCreation;
- (BOOL)shouldCancelDependencyGraphCreation;
- (id)commandWithNumber:(unsigned long long)arg1;
- (unsigned long long)numberOfCommands;
- (id)commands;
- (id)createCommandWithPath:(id)arg1 ruleInfo:(id)arg2;
- (id)createCommandWithRuleInfo:(id)arg1 commandPath:(id)arg2 arguments:(id)arg3 forNode:(id)arg4;
- (void)registerDependencyCommand:(id)arg1;
- (id)invokeTask:(id)arg1 forInputs:(id)arg2 options:(id)arg3;
- (id)invokeTask:(id)arg1 forInputs:(id)arg2 optionDictionary:(id)arg3;
- (void)_addMappingFromPath:(id)arg1 toNode:(id)arg2;
- (id)dependencyNodeWithNumber:(unsigned long long)arg1;
- (unsigned long long)numberOfDependencyNodes;
- (id)dependencyNodeForName:(id)arg1;
- (void)removeAllCompilerRequestedLinkerParameters;
- (void)addCompilerRequestedLinkerParameters:(id)arg1;
- (id)compilerRequestedLinkerParameters;
- (void)addCommandToRerun:(id)arg1 name:(id)arg2;
- (void)setAutoIncrementsPhaseNumber:(BOOL)arg1;
- (BOOL)autoIncrementsPhaseNumber;
- (void)incrementCurrentPhaseNumber;
- (unsigned long long)currentPhaseNumber;
- (id)dependencyNodeForName:(id)arg1 createIfNeeded:(BOOL)arg2;
- (id)preprocessingInfoForIndexingSourceFilesWithCompiler:(id)arg1 languageDialect:(id)arg2;
- (id)preprocessingInfoDictionaries;
- (id)headerFileSearchContextForSourceFilesUsingCompiler:(id)arg1 languageDialect:(id)arg2;
- (id)_searchPathsForCurrentStateAndOtherFlagsBuildSettingsName:(id)arg1 builtinSystemHeaderSearchPaths:(id)arg2 builtinFrameworkSearchPaths:(id)arg3;
- (void)removeSearchPathArgumentsFromArrayOfCommandLineArguments:(id)arg1;
- (id)effectivePlatform;
- (id)effectiveSDKPackage;
- (void)dependencyGraphCreationDidComplete;
- (void)createDependencyGraphWithTargetDGSnapshot:(id)arg1;
- (BOOL)doesCurrentThreadHoldDependencyGraphLock;
- (void)unlockDependencyGraph;
- (void)lockDependencyGraph;
- (BOOL)lockDependencyGraphBeforeDate:(id)arg1;
- (id)naturalPathForPath:(id)arg1;
- (id)absolutePathForPath:(id)arg1;
- (id)baseDirectoryPath;
- (BOOL)hasPopulatedAuxiliaryBuildInfo;
- (id)distributedBuildToolCommandPath;
- (int)distributedBuildSystemInUse;
- (BOOL)shouldUseDistributedBuilds;
- (void)enableCacheInvalidation;
- (void)disableCacheInvalidation;
- (void)_activeSDKDidChange:(id)arg1;
- (void)_activeBuildConfigurationNameDidChange:(id)arg1;
- (void)_projectWillClose:(id)arg1;
- (id)platformDomain;
- (id)targetSnapshot;
- (void)setOverridingProperties:(id)arg1;
- (id)overridingProperties;
- (void)setPresumedActiveArchitecture:(id)arg1;
- (id)presumedActiveArchitecture;
- (void)setPresumedBuildConfigurationName:(id)arg1;
- (id)presumedBuildConfigurationName;
- (void)setPresumedBuildAction:(id)arg1;
- (id)presumedBuildAction;
- (void)invalidate;
- (id)target;
- (void)dealloc;
- (id)initWithTarget:(id)arg1;
- (void)dg_untouchNodeForFileAtPath:(id)arg1;
- (void)untouchNodeForFileAtPath:(id)arg1;
- (void)dg_touchNodeForFileAtPath:(id)arg1;
- (void)touchNodeForFileAtPath:(id)arg1;
- (void)dg_noteFileSystemDidChangeAtPath:(id)arg1;
- (void)noteFileSystemDidChangeAtPath:(id)arg1;
- (void)waitForDependencyGraph;
- (void)noteTargetSnapshotDidPrepareToCreateDependencies;
- (void)finishedSettingTargetSnapshot;
- (void)dg_setTargetSnapshot:(id)arg1;
- (void)setTargetSnapshot:(id)arg1;
- (void)processDependencyGraphEvents;
- (void)enqueueDependencyGraphEventInvocation:(id)arg1;
@end

@interface XCSpecification : NSObject
{
    NSString *_identifier;
    XCSpecification *_superSpecification;
    NSDictionary *_properties;
    NSDictionary *_localizationDictionary;
}

+ (BOOL)_booleanValueForValue:(id)arg1;
+ (void)loadSpecificationsWithProperty:(id)arg1;
+ (Class)specificationBaseClassForType:(id)arg1;
+ (id)specificationTypeForPathExtension:(id)arg1;
+ (id)allRegisteredSpecifications;
+ (id)registeredBaseSpecifications;
+ (id)registeredBaseSpecificationsInDomain:(id)arg1;
+ (id)_subSpecificationsOfSpecification:(id)arg1 inDomain:(id)arg2;
+ (id)registeredSpecifications;
+ (id)registeredSpecificationsInDomain:(id)arg1;
+ (id)registeredSpecificationsInDomainOrDefault:(id)arg1;
+ (id)specificationsForIdentifiers:(id)arg1;
+ (id)specificationsForIdentifiers:(id)arg1 inDomain:(id)arg2;
+ (id)specificationForIdentifier:(id)arg1;
+ (id)specificationForIdentifier:(id)arg1 inDomain:(id)arg2;
+ (void)_getDomain:(id *)arg1 identifier:(id *)arg2 fromDomainPrefixedIdentifier:(id)arg3;
+ (id)registerSpecificationProxiesFromPropertyListsInDirectory:(id)arg1 recursively:(BOOL)arg2;
+ (id)registerSpecificationProxiesFromPropertyListsInDirectory:(id)arg1 recursively:(BOOL)arg2 inDomain:(id)arg3;
+ (id)registerSpecificationProxiesFromPropertyListsInDirectory:(id)arg1 recursively:(BOOL)arg2 inDomain:(id)arg3 inBundle:(id)arg4;
+ (BOOL)_shouldRecurseIntoDirectoryNamed:(id)arg1 ofType:(id)arg2;
+ (id)_registerSpecificationProxiesOfType:(id)arg1 fromDictionaryOrArray:(id)arg2 inDirectory:(id)arg3 bundle:(id)arg4 sourceDescription:(id)arg5 inDomain:(id)arg6;
+ (id)registerSpecificationProxyFromPropertyList:(id)arg1;
+ (id)registerSpecificationProxyFromPropertyList:(id)arg1 inDomain:(id)arg2;
+ (void)registerSpecificationOrProxy:(id)arg1;
+ (void)registerSpecificationTypeBaseClass:(Class)arg1;
+ (id)_pathExensionsToTypesRegistry;
+ (id)_typesToSpecTypeBaseClassesRegistry;
+ (id)specificationRegistryForDomain:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)description;
- (id)valueForUndefinedKey:(id)arg1;
- (id)arrayOrStringForKey:(id)arg1;
- (BOOL)boolForKeyFromProxy:(id)arg1;
- (BOOL)boolForKey:(id)arg1;
- (double)doubleForKey:(id)arg1;
- (float)floatForKey:(id)arg1;
- (long long)longLongForKey:(id)arg1;
- (long long)integerForKey:(id)arg1;
- (id)dataForKey:(id)arg1;
- (id)dictionaryForKey:(id)arg1;
- (id)arrayForKey:(id)arg1;
- (id)stringForKey:(id)arg1;
- (id)objectForKey:(id)arg1;
- (id)_objectForKeyIgnoringInheritance:(id)arg1;
- (long long)nameCompare:(id)arg1;
- (long long)identifierCompare:(id)arg1;
- (id)localizedDescription;
- (id)name;
- (id)domain;
- (id)bundle;
- (id)localizationDictionary;
- (id)properties;
- (id)type;
- (id)identifier;
- (BOOL)isMissingSpecificationProxy;
- (id)loadedSpecification;
- (BOOL)isNotYetLoadedSpecificationProxy;
- (BOOL)isAbstract;
- (BOOL)isKindOfSpecification:(id)arg1;
- (id)subSpecifications;
- (id)subSpecificationsInDomain:(id)arg1;
- (id)superSpecification;
- (void)dealloc;
- (id)init;
- (id)initAsMissingSpecificationProxyWithIdentifier:(id)arg1 name:(id)arg2 description:(id)arg3 inDomain:(id)arg4;
- (id)initWithPropertyListDictionary:(id)arg1;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface XCPropertyDomainSpecification : XCSpecification
{
    NSDictionary *_buildOptions;
    NSArray *_orderedBuildOptions;
    NSArray *_optionNamesForCommandLine;
    NSArray *_buildOptionCategories;
    NSSet *_buildOptionConditionFlavors;
    XCPropertyDomainSpecification *_specForUserInterface;
    NSDictionary *_flattenedBuildOptions;
    NSArray *_flattenedOrderedBuildOptions;
    NSArray *_flattenedCommonBuildOptions;
    NSArray *_flattenedOptionNamesForCommandLine;
    NSArray *_flattenedOptionCategories;
}

+ (id)propertyDomainForIdentifier:(id)arg1 inSpecificationDomain:(id)arg2;
+ (id)allRegisteredPropertyDomainsInSpecificationDomain:(id)arg1;
+ (id)dictionaryOfallRegisteredPropertyDomainsInSpecificationDomain:(id)arg1;
+ (void)registerSpecificationOrProxy:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)commandLineForAutogeneratedOptionsForKey:(id)arg1 inTargetBuildContext:(id)arg2;
- (id)_expandedValueForCommandLineBuildOptionNamed:(id)arg1 inBuildContext:(id)arg2;
- (id)defaultValuesForAllOptions;
- (id)specificationToShowInUserInterface;
- (id)buildOptionConditionFlavors;
- (id)namesOfFlattenedOptionsForCommandLine;
- (id)namesOfBuildOptionsForCommandLine;
- (id)flattenedOptionCategories;
- (id)buildOptionCategories;
- (id)orderedBuildOptions;
- (id)buildOptionNamed:(id)arg1;
- (id)buildOptions;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface XCCommandLineToolSpecification : XCPropertyDomainSpecification
{
}

+ (id)unionedDefaultValuesForAllPropertiesForAllToolsInDomain:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)instantiatedCommandResultsPostprocessorForCommand:(id)arg1;
- (unsigned long long)concurrentExecutionCountInTargetBuildContext:(id)arg1;
- (id)createCommandsforInputs:(id)arg1 inBuildContext:(id)arg2;
- (void)editArgumentsForCommand:(id)arg1 inBuildContext:(id)arg2;
- (id)doSpecialDependencySetupForCommand:(id)arg1 withInputNodes:(id)arg2 inBuildContext:(id)arg3;
- (id)outputPathFromInputNodes:(id)arg1 inBuildContext:(id)arg2;
- (id)executablePathInTargetBuildContext:(id)arg1;
- (void)checkDeploymentTargetAgainstSDKInTargetBuildContext:(id)arg1;
- (void)_addNameToDefaultValueMappingsToMutableDictionary:(id)arg1;
- (id)identifiersOfBuildPhasesForWhichToSynthesizeBuildRules;
- (BOOL)shouldSynthesizeGlobalBuildRule;
- (id)instantiatedCommandOutputParserWithLogSectionRecorder:(id)arg1;
- (id)arrayByRemovingArgumentsNotAffectingOutputFileFromArray:(id)arg1;
- (BOOL)areOutputFilesAffectedByEnvironmentVariable:(id)arg1;
- (BOOL)areOutputFilesAffectedByCommandLineArgument:(id)arg1;
- (id)commandLineForAutogeneratedOptionsInTargetBuildContext:(id)arg1;
- (id)_expandedValueForCommandLineBuildOptionNamed:(id)arg1 inBuildContext:(id)arg2;
- (id)hashStringForCommandLineComponents:(id)arg1 inputFilePaths:(id)arg2 inTargetBuildContext:(id)arg3;
- (id)requiredComponents;
- (void)setDefaultDeploymentTarget:(id)arg1 forName:(id)arg2;
- (id)defaultDeploymentTargetNamed:(id)arg1;
- (id)commandOutputParserClassesOrParseRules;
- (Class)commandInvocationClass;
- (BOOL)outputsAreProducts;
- (id)outputPaths;
- (BOOL)supportsArchitecture:(id)arg1;
- (BOOL)acceptsInputFileType:(id)arg1;
- (id)supportedArchitectures;
- (id)inputFileTypes;
- (id)ruleLineTemplate;
- (id)fallbackToolSpecificationsForDomain:(id)arg1;
- (id)path;
- (id)name;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface XCCompilerSpecification : XCCommandLineToolSpecification
{
    NSArray *_supportedArchs;
}

+ (id)specificationsToDisplayInDomain:(id)arg1;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)computeDependenciesForFilePath:(id)arg1 ofType:(id)arg2 outputDirectory:(id)arg3 inTargetBuildContext:(id)arg4;
- (id)computeDependenciesForInputFile:(id)arg1 ofType:(id)arg2 variant:(id)arg3 architecture:(id)arg4 outputDirectory:(id)arg5 inTargetBuildContext:(id)arg6;
- (id)adjustedFileTypeForInputFileAtPath:(id)arg1 originalFileType:(id)arg2 inTargetBuildContext:(id)arg3;
- (id)fileTypeForGccLanguageDialect:(id)arg1;
- (id)effectiveCompilerSpecificationForFileType:(id)arg1 inPropertyExpansionContext:(id)arg2 platformDomain:(id)arg3;
- (id)defaultOutputDirectory;
- (id)executablePath;
- (id)outputFilesForInputFilePath:(id)arg1 inTargetBuildContext:(id)arg2;
- (id)uniqueOutputBaseNameForInputFilePath:(id)arg1 inTargetBuildContext:(id)arg2;
- (id)builtinJambaseRuleName;
- (BOOL)isAbstract;
- (id)supportedArchitectures;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
- (id)builtinMacroDefinitionsInBuildContext:(id)arg1 forLanguageDialect:(id)arg2;
- (id)builtinFrameworkSearchPathsInBuildContext:(id)arg1 forLanguageDialect:(id)arg2;
- (id)builtinBracketSearchPathsInBuildContext:(id)arg1 forLanguageDialect:(id)arg2;
- (id)builtinQuoteSearchPathsInBuildContext:(id)arg1 forLanguageDialect:(id)arg2;
@end

@interface XCLinkerSpecification : XCCommandLineToolSpecification
{
    NSArray *_inputFileTypes;
}

+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)inputFileTypes;
- (id)architectures;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface PBXFileType : XCSpecification
{
    NSArray *_extensions;
}

+ (id)fileTypeForPath:(id)arg1;
+ (id)fileTypeUsingFileAttributesAtPath:(id)arg1;
+ (id)fileTypeForPath:(id)arg1 getExtraFileProperties:(id *)arg2;
+ (id)guessFileTypeForGenericFileAtPath:(id)arg1 withFileAttributes:(id)arg2 getExtraFileProperties:(id *)arg3;
+ (id)fileTypeForFilenamePattern:(id)arg1 isFolder:(BOOL)arg2;
+ (id)fileTypeMatchingPatternsForFileName:(id)arg1;
+ (id)fileTypeForFileName:(id)arg1;
+ (id)fileTypeForFileName:(id)arg1 posixPermissions:(unsigned long long)arg2 hfsTypeCode:(unsigned int)arg3 hfsCreatorCode:(unsigned int)arg4;
+ (id)bestFileTypeForRepresentingFileAtPath:(id)arg1 withFileAttributes:(id)arg2 withLessSpecificFileType:(id)arg3 getExtraFileProperties:(id *)arg4;
+ (id)wrapperFolderType;
+ (id)genericFolderType;
+ (id)textFileType;
+ (id)genericFileType;
+ (id)_fileTypeDetectorArray;
+ (id)_fileNamePatternToFileTypeDictionary;
+ (id)_magicWordToFileTypeDictionary;
+ (id)_lowercasedExtensionToFileTypeDictionary;
+ (id)_extensionToFileTypeDictionary;
+ (void)registerSpecificationOrProxy:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)description;
- (id)_objectForKeyIgnoringInheritance:(id)arg1;
- (id)fileTypePartForIdentifier:(id)arg1;
- (id)subpathForWrapperPart:(int)arg1 ofPath:(id)arg2 withExtraFileProperties:(id)arg3;
- (id)extraPropertyNames;
- (BOOL)requiresHardTabs;
- (BOOL)isScannedForIncludes;
- (id)plistStructureDefinitionIdentifier;
- (id)xcLanguageSpecificationIdentifier;
- (id)languageSpecificationIdentifier;
- (BOOL)canSetIncludeInIndex;
- (BOOL)isTransparent;
- (BOOL)includeInIndex;
- (BOOL)isWrapperFolder;
- (BOOL)isNonWrapperFolder;
- (BOOL)isFolder;
- (BOOL)isDocumentation;
- (BOOL)isSourceCode;
- (BOOL)isPreprocessed;
- (BOOL)isTextFile;
- (BOOL)isPlainFile;
- (BOOL)isExecutableWithGUI;
- (BOOL)isExecutable;
- (BOOL)isTargetWrapper;
- (BOOL)isProjectWrapper;
- (BOOL)isStaticFramework;
- (BOOL)isFramework;
- (BOOL)isStaticLibrary;
- (BOOL)isDynamicLibrary;
- (BOOL)isLibrary;
- (BOOL)isApplication;
- (BOOL)isBundle;
- (id)hfsTypeCodes;
- (id)extensions;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface PBXTargetBuildContext (BDExtensions)
- (NSArray*)linkedLibraryPaths;
+ (void)activateImportedFileType:(PBXFileType*)type withCompiler:(XCCompilerSpecification*)spec;
@end

@protocol XCProductPartOwners
- (id)productPartForIdentifier:(id)fp8;
- (id)subpartsForProductPart:(id)fp8;
@end

@interface PBXBuildSettingsDictionary : NSMutableDictionary
{
    NSMutableDictionary *_buildSettings;
    NSMutableDictionary *_conditionalBuildSettings;
    NSMutableDictionary *_buildSettingToConditionSetMap;
    id _delegate;
    int _definitionLevel;
    struct {
        unsigned int delegateWantsWillSet:1;
        unsigned int delegateWantsDidSet:1;
        unsigned int delegateWantsShouldExtractQuotedBuildSettingsWhenSplitting:1;
        unsigned int RESERVED:29;
    } _bsFlags;
    unsigned long long _changeCount;
    unsigned long long _keyChangeCount;
    NSUndoManager *_undoManager;
}

+ (id)expandedBuildSettingForString:(id)arg1 withExpansionDictionaries:(id)arg2;
+ (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2;
+ (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2 returningLocalizedErrorString:(id *)arg3;
+ (id)dictionaryByParsingStringAsBuildSettingAssignments:(id)arg1 getLocalizedErrorString:(id *)arg2;
+ (id)buildSettingAssignmentParsedFromString:(id)arg1 getLocalizedErrorString:(id *)arg2;
+ (id)dictionaryWithDefinitionLevel:(int)arg1;
+ (id)dictionaryWithDictionary:(id)arg1 definitionLevel:(int)arg2;
+ (id)dictionaryWithDictionary:(id)arg1;
+ (id)dictionaryWithKeysAndObjects:(id)arg1;
+ (id)dictionary;
+ (void)initialize;
+ (id)_jambaseToNativeBuildSettingConversionRules;
- (id)descriptionWithLocale:(id)arg1 indent:(unsigned long long)arg2;
- (BOOL)upgradeBuildSettingsFromArchivedObjectVersion:(unsigned long long)arg1;
- (id)project;
- (void)setDelegate:(id)arg1;
- (id)delegate;
- (int)definitionLevel;
- (void)setDefinitionLevel:(int)arg1;
- (unsigned long long)keyChangeCount;
- (unsigned long long)changeCount;
- (id)undoManager;
- (void)appendStringList:(id)arg1 toStringListBuildSettingForKey:(id)arg2;
- (void)setStringListBuildSetting:(id)arg1 forKey:(id)arg2;
- (id)stringListBuildSettingForKey:(id)arg1;
- (id)conditionSetsForKeyPath:(id)arg1;
- (id)orderedConditionalDictionariesForConditionSet:(id)arg1;
- (id)conditionalDictionaryForConditionSet:(id)arg1;
- (id)conditionalDictionaries;
- (id)conditionSets;
- (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2;
- (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2 returningLocalizedErrorString:(id *)arg3;
- (BOOL)isConditional;
- (void)removeBuildSettingForKeyPath:(id)arg1;
- (void)setBuildSetting:(id)arg1 forKeyPath:(id)arg2;
- (void)setBuildSetting:(id)arg1 forKeyPath:(id)arg2 conditionSet:(id)arg3;
- (void)setBuildSetting:(id)arg1 operation:(int)arg2 forKeyPath:(id)arg3;
- (id)buildSettingForKeyPath:(id)arg1;
- (id)buildSettingForKeyPath:(id)arg1 conditionSet:(id)arg2;
- (id)buildSettingForKeyPath:(id)arg1 getOperation:(int *)arg2;
- (void)removeBuildSettingForKeyPath:(id)arg1 conditionSet:(id)arg2;
- (void)setBuildSetting:(id)arg1 operation:(int)arg2 forKeyPath:(id)arg3 conditionSet:(id)arg4;
- (id)buildSettingForKeyPath:(id)arg1 conditionSet:(id)arg2 getOperation:(int *)arg3;
- (BOOL)isEqualToDictionary:(id)arg1;
- (void)addEntriesFromDictionary:(id)arg1;
- (void)removeObjectForKey:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (id)objectForKey:(id)arg1;
- (id)allValues;
- (id)allKeys;
- (id)keyEnumerator;
- (unsigned long long)count;
- (void)_undoRedoBuildSettingOperation:(id)arg1;
- (id)_buildSettings;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)_unarchiveArchsStandardSettingsUsingDict:(id)arg1;
- (void)_archiveArchsStandardSettingsUsingDict:(id)arg1;
- (id)_absoluteArchiveRepresentationForSDKROOTValue:(id)arg1;
- (id)_unarchivedRepresentationForSDKROOTValue:(id)arg1;
- (id)initFromArchivedDictionaryRepresentation:(id)arg1;
- (id)archivedDictionaryRepresentation;
- (void)dealloc;
- (id)initWithCapacity:(unsigned long long)arg1;
- (id)init;
- (id)initWithDictionary:(id)arg1;
- (id)initWithDictionaryNoCopy:(id)arg1;
- (void)_extractConditionalDictionaries;
- (void)_setObject:(id)arg1 forKey:(id)arg2 conditionSet:(id)arg3;
- (void)convertBuildSettingsFromJambasedToNativeForTarget:(id)arg1 withUpgradeLog:(id)arg2;
@end

@interface XCProductTypeSpecification : XCSpecification <XCProductPartOwners>
{
    PBXBuildSettingsDictionary *_defaultBuildSettings;
    PBXBuildSettingsDictionary *_flattenedDefaultBuildSettings;
    NSSet *_allowedBuildPhaseClasses;
    NSArray *_packageTypes;
    NSArray *_productParts;
}

+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)createUniversalBinaryFromThinBinaries:(id)arg1 inTargetBuildContext:(id)arg2;
- (void)addInstallNameLinkerFlagsInTargetBuildContext:(id)arg1;
- (void)addWarningLinkerFlagsInTargetBuildContext:(id)arg1;
- (void)addBaseLinkerFlagsInTargetBuildContext:(id)arg1;
- (id)linkerSpecificationForObjectFilesInTargetBuildContext:(id)arg1;
- (BOOL)shouldStripSymbolsOfLinkedProductInTargetBuildContext:(id)arg1;
- (void)compileAuxiliaryFilesForVariant:(id)arg1 architecture:(id)arg2 inTargetBuildContext:(id)arg3;
- (id)computeProductTouchActionInTargetBuildContext:(id)arg1;
- (void)computeSymlinkDependenciesInTargetBuildContext:(id)arg1;
- (void)changePermissionsOnProductInTargetBuildContext:(id)arg1;
- (void)_computeDependenciesForOwner:(id)arg1 group:(id)arg2 mode:(id)arg3 onFile:(id)arg4 inTargetBuildContext:(id)arg5;
- (void)rebuildProductInTargetBuildContext:(id)arg1;
- (void)setAlternatePermissionsOnProductInTargetBuildContext:(id)arg1;
- (void)separatelyStripSymbolsOfLinkedProductInTargetBuildContext:(id)arg1;
- (void)editSymbolsOfLinkedProductInTargetBuildContext:(id)arg1;
- (void)copyAsideProductInTargetBuildContext:(id)arg1;
- (void)runWorkQueuePhase:(unsigned long long)arg1 perVariantInTargetBuildContext:(id)arg2;
- (void)runWorkQueuePhase:(unsigned long long)arg1 inTargetBuildContext:(id)arg2;
- (void)finishPostProcessingProductInTargetBuildContext:(id)arg1;
- (void)beginPostProcessingProductInTargetBuildContext:(id)arg1;
- (void)codeSignProductInTargetBuildContext:(id)arg1;
- (void)definePlatformSpecificAuxiliaryFilesInTargetBuildContext:(id)arg1;
- (void)defineAuxiliaryFilesInTargetBuildContext:(id)arg1;
- (void)alterBuildSettingsWhereNecessaryInTargetBuildContext:(id)arg1;
- (id)_prependSDKPath:(id)arg1 toPath:(id)arg2;
- (void)computeProductDependenciesInTargetBuildContext:(id)arg1;
- (void)initializeBuildSettingsInTargetBuildContext:(id)arg1;
- (void)initializeTemporaryBuildSettingsInTargetBuildContext:(id)arg1;
- (void)computeDependenciesInTargetBuildContext:(id)arg1;
- (id)iconNamePrefix;
- (BOOL)hasInfoPlist;
- (id)subpartsForProductPart:(id)arg1;
- (id)productPartForIdentifier:(id)arg1;
- (id)productParts;
- (id)defaultPackageType;
- (id)packageTypes;
- (id)allowedBuildPhaseClasses;
- (id)defaultBuildSettings_asPropertyValues;
- (id)defaultBuildSettings;
- (id)defaultTargetName;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface PBXPackageTypeSpecification : XCSpecification
{
    PBXBuildSettingsDictionary *_defaultBuildSettings;
    PBXBuildSettingsDictionary *_flattenedDefaultBuildSettings;
    NSString *_productReferenceFileTypeIdentifier;
    PBXFileType *_productReferenceFileType;
    NSString *_productReferenceName;
    BOOL _productReferenceIsLaunchable;
}

+ (id)wrapperSubpathForWrapperPart:(int)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (BOOL)productReferenceIsLaunchable;
- (id)productReferenceName;
- (id)productReferenceFileType;
- (id)defaultBuildSettings_asPropertyValues;
- (id)defaultBuildSettings;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface PBXRuntimeSystemSpecification : XCSpecification
{
}

+ (id)nativeRuntimeSystemSpecificaton;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)specificResourcePath;
- (id)infoPlistKey;
@end

@interface PBXBuildSettingsPaneSpecification : XCSpecification
{
    NSString *_settingsDomainPath;
    NSString *_paneClassName;
    NSString *_paneFollows;
    NSArray *_widgets;
}

+ (id)registeredSpecificationsSorted;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationBaseClass;
- (id)widgets;
- (id)paneFollows;
- (Class)paneClass;
- (id)paneClassName;
- (id)settingsDomainPath;
- (id)name;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface PBXSCMSpecification : XCSpecification
{
    NSString *_classBaseName;
    BOOL _canAddDirectories;
    BOOL _canRenameFiles;
    BOOL _canPerformOffline;
    NSString *_repositoryClassName;
}

+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (BOOL)canPerformOffline;
- (BOOL)canRenameFiles;
- (BOOL)canAddDirectories;
- (Class)repositoryClass;
- (id)repositoryClassName;
- (id)classBaseName;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface XCArchitectureSpecification : XCSpecification
{
    long long _byteOrder;
    NSString *_canonicalName;
    NSString *_userVisibleName;
    NSArray *_realArchitectures;
    NSString *_architectureSetting;
    _Bool _isShownInPopup;
    int _sortNumber;
    NSArray *_compatibilityArchs;
}

+ (id)validArchitectureCanonicalNamesInDomain:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)compatibilityArchitectures;
- (int)sortNumber;
- (_Bool)isShownInPopup;
- (id)architectureSetting;
- (id)realArchitectures;
- (id)userVisibleName;
- (id)canonicalName;
- (long long)byteOrder;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface XCPlatformSpecification : XCSpecification
{
    NSString *_name;
    NSArray *_alternateNames;
    NSString *_directoryName;
    NSString *_path;
    NSString *_iconPath;
    NSString *_userDescription;
//    DTDeveloperPaths *_developerPaths;
//    DTDeveloperPaths *_pluginDeveloperPaths;
    NSMutableArray *_projectTemplatePaths;
    NSMutableArray *_targetTemplatePaths;
    NSMutableArray *_fileTemplatePaths;
    PBXBuildSettingsDictionary *_defaultProperties;
    PBXBuildSettingsDictionary *_overrideProperties;
    NSDictionary *_deviceProperties;
    NSMutableArray *_SDKs;
//    XCSDKPackage *_defaultSDK;
    NSString *_familyName;
    NSString *_familyIdentifier;
    NSString *_runtimeSystemSpecification;
    NSDictionary *_validationDict;
    NSMutableDictionary *_debuggerSettings;
}

+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
+ (id)platformForExpansionContext:(id)arg1;
+ (id)platformForPath:(id)arg1;
+ (id)platformForDomain:(id)arg1;
+ (id)platformForName:(id)arg1;
+ (id)allPlatforms;
+ (void)loadAllPlatforms;
+ (void)_loadPlatformAtPath:(id)arg1 andSpecificationsAndPlugins:(BOOL)arg2;
+ (void)registerSpecificationOrProxy:(id)arg1;
+ (void)_mapPlatformName:(id)arg1 toSpecificationOrProxy:(id)arg2 isAlias:(BOOL)arg3;
+ (id)defaultPlatform;
+ (id)_propertyDictionaryForPlatformAtPath:(id)arg1;
+ (void)initialize;
- (id)dataformattersBundleStyle;
- (id)dataformattersLocationPath;
- (BOOL)providesAttachList;
- (BOOL)debuggerCanUseGuardMalloc;
- (BOOL)debuggerCanRestart;
- (BOOL)runInDebugger;
- (BOOL)deviceIsRequiredForLaunch;
- (BOOL)_debuggerSettingIsEnabledForKey:(id)arg1;
- (id)_debuggerSettingForKey:(id)arg1;
- (id)debuggerSettings;
- (id)overridingRuntimeSystemSpecification;
- (id)fileTemplateSearchPaths;
- (id)targetTemplateSearchPaths;
- (id)projectTemplateSearchPaths;
- (id)defaultSDK;
- (void)addSDK:(id)arg1;
- (id)SDKs;
- (id)deviceProperties;
- (id)overrideProperties;
- (id)defaultProperties;
- (id)_computedProperties:(id)arg1;
- (id)pluginDeveloperPaths;
- (id)developerPaths;
- (id)userDescription;
- (id)iconPath;
- (id)familyIdentifier;
- (id)familyName;
- (id)platformDomain;
- (id)path;
- (id)directoryName;
- (id)alternateNames;
- (id)name;
- (BOOL)isPlatformFullyLoaded;
- (void)loadSpecificationsAndPlugins;
- (void)_prependPlatformPathToSearchPathsIfNecessary:(id)arg1;
- (void)dealloc;
- (id)initWithPath:(id)arg1;
- (id)initWithPropertyListDictionary:(id)arg1 path:(id)arg2 inDomain:(id)arg3;
@end

@interface PBXSourceTokens : NSObject
{
    NSMutableSet *_tokens;
    BOOL _caseSensitive;
}

+ (long long)addTokenForString:(id)arg1;
+ (long long)_tokenForString:(id)arg1;
- (id)allTokens;
- (long long)tokenForString:(id)arg1;
- (BOOL)containsToken:(id)arg1;
- (void)addArrayOfStrings:(id)arg1;
- (void)dealloc;
- (id)initWithArrayOfStrings:(id)arg1 caseSensitive:(BOOL)arg2;
@end

@interface PBXLexicalRules : NSObject
{
    NSMutableCharacterSet *_commentStartChars;
    NSMutableCharacterSet *_endCommentStartChars;
    NSMutableCharacterSet *_singleLineCommentStartChars;
    NSMutableCharacterSet *_stringStartChars;
    NSMutableCharacterSet *_endStringStartChars;
    NSMutableCharacterSet *_charStartChars;
    NSMutableCharacterSet *_endCharStartChars;
    NSMutableCharacterSet *_identifierStartChars;
    NSMutableCharacterSet *_identifierChars;
    NSCharacterSet *_nonIdentifierCharacters;
    NSMutableCharacterSet *_numericStartChars;
    NSMutableCharacterSet *_numericChars;
    NSMutableCharacterSet *_endOfLineChars;
    NSCharacterSet *_whitespaceChars;
    NSCharacterSet *_nonWhitespaceChars;
    PBXSourceTokens *_keywords;
    PBXSourceTokens *_altKeywords;
    PBXSourceTokens *_docCommentKeywords;
    PBXSourceTokens *_preprocessorKeywords;
    NSMutableArray *_stringDelimiters;
    NSMutableArray *_commentDelimiters;
    NSMutableArray *_singleLineComment;
    NSMutableArray *_characterDelimiters;
    NSString *_docComment;
    unsigned short _docCommentKeywordStart;
    unsigned short _preprocessorKeywordStart;
    unsigned short _escapeCharacter;
    NSCharacterSet *_linkStartChars;
    NSCharacterSet *_linkPrefixChars;
    NSCharacterSet *_urlLocationChars;
    NSCharacterSet *_domainNameStartChars;
    NSCharacterSet *_domainNameChars;
    NSString *_urlSchemeDelimiter;
    NSString *_mailLocalNameDelimiter;
    BOOL _caseSensitive;
    BOOL _unicodeSymbols;
    BOOL _indexedSymbols;
    BOOL _commentsCanBeNested;
    BOOL _fortranStyleComments;
}

- (BOOL)isNumber:(id)arg1 withRange:(struct _NSRange *)arg2;
- (long long)tokenForString:(id)arg1;
- (BOOL)fortranStyleComments;
- (BOOL)commentsCanBeNested;
- (BOOL)indexedSymbols;
- (BOOL)unicodeSymbols;
- (BOOL)caseSensitive;
- (id)domainNameChars;
- (id)urlLocationChars;
- (id)linkPrefixChars;
- (id)mailLocalNameDelimiter;
- (id)urlSchemeDelimiter;
- (unsigned short)docCommentKeywordStart;
- (unsigned short)preprocessorKeywordStart;
- (unsigned short)escapeCharacter;
- (id)docComment;
- (id)characterDelimiters;
- (id)singleLineComment;
- (id)commentDelimiters;
- (id)stringDelimiters;
- (id)preprocessorKeywords;
- (id)docCommentKeywords;
- (id)altKeywords;
- (id)keywords;
- (BOOL)isPreprocessorKeyword:(id)arg1;
- (BOOL)isDocCommentKeyword:(id)arg1;
- (BOOL)isAltKeyword:(id)arg1;
- (BOOL)isKeyword:(id)arg1;
- (id)nonWhitespaceCharacterSet;
- (id)nonIdentifierCharacterSet;
- (BOOL)isDomainNameStartChar:(unsigned short)arg1;
- (BOOL)isLinkStartChar:(unsigned short)arg1;
- (BOOL)isWhitespaceChar:(unsigned short)arg1;
- (BOOL)isEndOfLineChar:(unsigned short)arg1;
- (BOOL)isNumericChar:(unsigned short)arg1;
- (BOOL)isNumericStartChar:(unsigned short)arg1;
- (BOOL)isIdentifierChar:(unsigned short)arg1;
- (BOOL)isIdentifierStartChar:(unsigned short)arg1;
- (BOOL)isEndCharStartChar:(unsigned short)arg1;
- (BOOL)isCharStartChar:(unsigned short)arg1;
- (BOOL)isEndStringStartChar:(unsigned short)arg1;
- (BOOL)isStringStartChar:(unsigned short)arg1;
- (BOOL)isSingleLineCommentStartChar:(unsigned short)arg1;
- (BOOL)isEndCommentStartChar:(unsigned short)arg1;
- (BOOL)isCommentStartChar:(unsigned short)arg1;
- (void)addDictionary:(id)arg1;
- (id)initWithDictionary:(id)arg1;
- (id)init;
@end

@interface PBXLanguageSpecification : XCSpecification
{
    NSDictionary *_syntaxColoringRules;
    NSDictionary *_indentationRules;
    NSString *_scannerClassName;
    Class _scannerClass;
    NSString *_lexerClassName;
    Class _lexerClass;
    PBXLexicalRules *_lexRules;
    BOOL _supportsSyntaxAwareIndenting;
}

+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
- (id)lexicalRules;
- (id)loadBaseLexicalRules;
- (id)sourceLexer;
- (id)sourceScanner;
- (BOOL)supportsSyntaxAwareIndenting;
- (id)indentationRules;
- (id)syntaxColoringRules;
- (void)dealloc;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
@end

@interface PBXSourceLexer : NSObject
{
    PBXLexicalRules *_rules;
    struct _NSRange _tokenRange;
    NSString *_tokenString;
    id _delegate;
    BOOL _ignoreNewLines;
    BOOL fortranStyleComments;
    NSMutableData *characterMapData;
    char *characterMap;
//    XCAttributeRun *_tokenRun;
}

- (void)skipToEndDelimeter:(unsigned short)arg1 withStart:(unsigned short)arg2;
- (BOOL)inputIsInSet:(id)arg1;
- (BOOL)inputMatchesString:(id)arg1;
- (void)skipToEndOfLineWithEscape:(BOOL)arg1;
- (void)skipToString:(id)arg1 withEscape:(BOOL)arg2;
- (void)skipToCharacter:(unsigned short)arg1 withEscape:(BOOL)arg2;
- (unsigned short)skipToCharacter:(unsigned short)arg1 orCharacter:(unsigned short)arg2 withEscape:(BOOL)arg3;
- (struct _NSRange)tokenRange;
- (id)stringForRange:(struct _NSRange)arg1;
- (void)setTokenStringToRange:(struct _NSRange)arg1;
- (id)tokenString;
- (long long)peekToken;
- (long long)cachedTokenTypeAtLocation:(unsigned long long)arg1 tokenRange:(struct _NSRange *)arg2;
- (void)stringWasEdited:(struct _NSRange *)arg1 replacementLength:(long long)arg2;
- (long long)nextToken:(BOOL)arg1;
- (long long)nextToken;
- (long long)_nextToken;
- (void)buildCharacterMap;
- (void)skipMultiLineCommentFromLoc:(unsigned long long)arg1 matchIndex:(long long)arg2;
- (void)scanForLinksInRange:(struct _NSRange)arg1;
- (void)parseDocCommentFromLoc:(unsigned long long)arg1 matchIndex:(long long)arg2;
- (unsigned long long)_matchInArray:(id)arg1 atIndex:(long long)arg2;
- (long long)_matchIn2DArray:(id)arg1 atIndex:(long long)arg2;
- (unsigned long long)length;
- (void)decLocation;
- (void)incLocation;
- (void)setLocation:(unsigned long long)arg1;
- (unsigned long long)curLocation;
- (unsigned long long)peekCharacterInSet:(id)arg1;
- (unsigned short)peekCharWithoutSkippingWhitespace;
- (unsigned short)peekChar;
- (unsigned short)nextChar;
- (unsigned short)nextCharWithoutSkippingWhitespace;
- (void)skipWhitespace;
- (void)setIgnoreNewLines:(BOOL)arg1;
- (id)rules;
- (void)scanSubRange:(struct _NSRange)arg1 startingInState:(int)arg2;
- (void)setString:(id)arg1 range:(struct _NSRange)arg2;
- (void)setDelegate:(id)arg1;
- (void)dealloc;
- (id)initWithLexicalRules:(id)arg1;
- (void)gotMailAddressForRange:(struct _NSRange)arg1;
- (void)gotURLForRange:(struct _NSRange)arg1;
- (void)gotPreprocessorForRange:(struct _NSRange)arg1;
- (void)gotIdentifierForRange:(struct _NSRange)arg1;
- (void)gotAltKeywordForRange:(struct _NSRange)arg1;
- (void)gotKeywordForRange:(struct _NSRange)arg1;
- (void)gotDocCommentKeywordForRange:(struct _NSRange)arg1;
- (void)gotDocCommentForRange:(struct _NSRange)arg1;
- (void)gotMultilineCommentForRange:(struct _NSRange)arg1;
- (void)gotCommentForRange:(struct _NSRange)arg1;
- (void)gotNumberForRange:(struct _NSRange)arg1;
- (void)gotStringForRange:(struct _NSRange)arg1;
- (void)gotCharacterForRange:(struct _NSRange)arg1;
@end

@interface PBXSourceScanner : NSObject
{
    PBXSourceLexer *_lexer;
}

- (id)parse;
- (id)parseString:(id)arg1;
- (void)initInterestingSymbols;
- (void)initSourceLexerForSpecification:(id)arg1;
- (id)lexer;
- (void)dealloc;
- (id)initWithLanguageSpecification:(id)arg1;
@end

@protocol PBXScannerItem <NSObject>
- (long long)compareWithScannerItem:(id <PBXScannerItem>)arg1;
- (int)type;
- (NSString *)nameWithIndent;
- (NSString *)name;
@end

@interface PBXSourceScannerItem : NSObject <PBXScannerItem>
{
    NSString *name;
    NSMutableArray *children;
    int type;
    PBXSourceScannerItem *parent;
    struct _NSRange nameRange;
    struct _NSRange range;
    long long nestingLevel;
    long long indentLevel;
}

- (long long)compareWithScannerItem:(id)arg1;
- (void)setIndentLevel:(long long)arg1;
- (long long)indentLevel;
- (void)setNestingLevel:(long long)arg1;
- (long long)nestingLevel;
- (void)setRange:(struct _NSRange)arg1;
- (struct _NSRange)range;
- (void)setNameRange:(struct _NSRange)arg1;
- (struct _NSRange)nameRange;
- (void)setParent:(id)arg1;
- (id)parent;
- (BOOL)isDeclaration;
- (void)setType:(int)arg1;
- (int)type;
- (id)children;
- (long long)numberOfChildren;
- (id)childAtIndex:(long long)arg1;
- (void)addChild:(id)arg1;
- (void)setName:(id)arg1;
- (id)nameWithIndent;
- (id)name;
@property(readonly, copy) NSString *description;
- (void)dealloc;
- (id)initWithName:(id)arg1 type:(long long)arg2;
@end

@interface XCDependencyNode : NSObject
{
    unsigned long long _nodeNumber;
    NSString *_name;
    NSString *_path;
    PBXTargetBuildContext *_buildContext;
    NSMutableArray *_producerCommands;
    NSMutableArray *_includedNodes;
    NSMutableArray *_consumerCommands;
    NSMutableArray *_includingNodes;
    struct {
        unsigned int alwaysOutOfDate:1;
        unsigned int dontCareIfExists:1;
        unsigned int dontCareAboutTimestamp:1;
        unsigned int shouldScanForIncludes:1;
        unsigned int beingEnqueued:1;
        unsigned int beingReset:1;
        unsigned int synchronizeCommands:1;
    } _dnFlags;
    unsigned int _traversalGenCount;
//    XCDerivedFileCache *_derivedFileCache;
//    XCBuildInfo *_buildInfo;
    int _state;
    int _highestInclState;
    long long _time;
    long long _newestInclTime;
//    CDStruct_7eef4560 _signature;
//    CDStruct_7eef4560 _combinedInclSignature;
    long long _fileSize;
    struct {
        long long modTime;
    } _node2009;
}

- (void)_2009_enqueueCommandsOntoWorkQueue:(id)arg1 whenceDebugDesc:(id)arg2;
- (long long)_2009_modTime;
- (void)writeInclusionEdgesToGraphVizFile:(struct __sFILE *)arg1;
- (void)writeDependencyEdgesToGraphVizFile:(struct __sFILE *)arg1;
- (void)writeDefinitionToGraphVizFile:(struct __sFILE *)arg1;
- (id)nameForGraphViz;
- (id)description;
- (id)shortNameForDebugging;
- (id)signatureDescription;
- (id)timeDescription;
- (id)stateDescription;
- (void)removeDiscoveredInfo;
- (void)updateDiscoveredBuildInfo;
- (void)untouch;
- (void)touch;
- (void)fileMayHaveChanged;
- (void)removePredictiveProcessingOutputRecursivelyBecauseOfChangedNode:(id)arg1;
- (void)resetStateRecursively;
- (void)resetState;
- (BOOL)isUpToDate;
- (void)enqueueOutOfDateCommandsOntoWorkQueue:(id)arg1;
- (void)computeStateIfNeeded;
- (void)statFileIfNeeded;
//- (void)setCommandInputSignature:(CDStruct_7eef4560)arg1 commandConfigurationSignature:(CDStruct_7eef4560)arg2;
//- (CDStruct_7eef4560)combinedSignatureOfIncludedNodes;
//- (CDStruct_7eef4560)signature;
- (long long)fileSize;
- (long long)newestTimestampOfIncludedNodes;
- (long long)timestamp;
- (int)highestStateOfIncludedNodes;
- (int)state;
- (BOOL)hasBeenUpdatedByClientId:(id)arg1;
- (void)unlockByClientId:(id)arg1;
- (BOOL)lockForWriting:(BOOL)arg1 byClientId:(id)arg2;
- (int)lockState;
- (id)derivedFileCache;
- (void)setSynchronizeCommandsOnDerivedFileCache:(id)arg1;
- (BOOL)synchronizeCommands;
- (void)setRecordsUpdatedFileListInEnvironment:(BOOL)arg1;
- (BOOL)recordsUpdatedFileListInEnvironment;
- (void)setDontCareAboutTimestamp:(BOOL)arg1;
- (BOOL)dontCareAboutTimestamp;
- (void)setDontCareIfExists:(BOOL)arg1;
- (BOOL)dontCareIfExists;
- (void)setAlwaysOutOfDate:(BOOL)arg1;
- (BOOL)isAlwaysOutOfDate;
- (void)_addConsumerCommand:(id)arg1;
- (void)_addProducerCommand:(id)arg1;
- (void)setScansFileContentsForIncludes:(BOOL)arg1;
- (void)removeAllIncludedNodes;
- (void)addIncludedNode:(id)arg1;
- (void)addDependedNode:(id)arg1;
- (void)_removeIncludingNode:(id)arg1;
- (void)_removeDependingNode:(id)arg1;
- (void)_addIncludingNode:(id)arg1;
- (void)_addDependingNode:(id)arg1;
- (void)invalidateCombinedIncludesSignature;
- (void)invalidateSignature;
//- (void)visitDownstreamCommandsUsingPreorderBlock:(CDUnknownBlockType)arg1 postorderBlock:(CDUnknownBlockType)arg2;
//- (void)_visitDownstreamCommandsUsingPreorderBlock:(CDUnknownBlockType)arg1 postorderBlock:(CDUnknownBlockType)arg2 recursionAvoidanceBitmap:(char *)arg3 whenceDebugDesc:(id)arg4;
//- (void)visitUpstreamCommandsUsingPreorderBlock:(CDUnknownBlockType)arg1 postorderBlock:(CDUnknownBlockType)arg2;
//- (void)_visitUpstreamCommandsUsingPreorderBlock:(CDUnknownBlockType)arg1 postorderBlock:(CDUnknownBlockType)arg2 recursionAvoidanceBitmap:(char *)arg3 whenceDebugDesc:(id)arg4;
- (void)makeConsumerCommandsPerformSelector:(SEL)arg1 withObject:(id)arg2;
- (void)makeConsumerCommandsPerformSelector:(SEL)arg1 withObject:(id)arg2 recursionAvoidanceBitmap:(char *)arg3;
- (void)decrementWaitCount;
- (void)incrementWaitCount;
- (void)setBuildInfo:(id)arg1;
- (id)buildInfo;
- (void)setAutomaticFileContents:(id)arg1;
- (id)automaticFileContents;
- (id)command;
- (id)producerCommand;
- (id)includingNodes;
- (id)consumerCommands;
- (id)includedNodes;
- (id)producerCommands;
- (id)dependencyInfoCacheEntry;
- (id)paths;
- (id)path;
- (BOOL)isVirtual;
- (id)name;
- (unsigned long long)nodeNumber;
- (id)buildNodeState;
- (void)setBuildContext:(id)arg1;
- (id)buildContext;
- (void)detachFromOtherGraphObjects;
- (void)dealloc;
- (id)init;
- (id)initWithNodeNumber:(unsigned long long)arg1 name:(id)arg2;
- (id)initWithNodeNumber:(unsigned long long)arg1 name:(id)arg2 path:(id)arg3;
- (const char *)unretainedFileSystemRepresentation;
@end

@interface XCDependencyCommand : /*XCWorkQueueCommand*/NSObject
{
    PBXTargetBuildContext *_buildContext;
    unsigned long long _commandNumber;
    NSMutableArray *_filePathsToRemove;
    unsigned long long _phaseNumber;
    NSMutableArray *_inputNodes;
    NSMutableArray *_outputNodes;
    XCCommandLineToolSpecification *_toolSpecification;
    NSArray *_ruleInfo;
    NSString *_commandPath;
    NSMutableArray *_arguments;
    NSMutableDictionary *_environment;
    NSString *_architecture;
    NSString *_variant;
    NSString *_workingDirPath;
    id _customToolInfoObject;
//    CDStruct_7eef4560 _inputSignature;
//    CDStruct_7eef4560 _configSignature;
    int _state;
    BOOL _waitCountBeingAdjusted;
    BOOL _beingEnqueued;
    BOOL _caresAboutIncludes;
    BOOL _mightHavePredProcOutput;
    BOOL _shouldSynchronizeOnFiles;
    BOOL _isBlockedOnFileLocks;
    BOOL _neededToRunWhenLastEnqueued;
    BOOL _emitEnvVars;
    NSMutableArray *_buildMessages;
    BOOL _specialEditingWasDone;
    NSString *_whyState;
//    XCWorkQueueCommandInvocation *_currentInvocation;
    NSString *_commandLineDisplayString;
//    XCPropertyDictionary *_launchPropertyDict;
    NSString *_extraSignatureInfo;
//    struct {
//        int state;
//        CDStruct_7eef4560 configSig;
//        NSString *whyDirty;
//        unsigned char markByte;
//    } _cmnd2009;
}

- (id)dependencyNode;
- (BOOL)outputFilesHaveBeenUpdated;
- (void)unlockInputAndOutputFiles;
- (void)lockInputAndOutputFiles;
- (BOOL)inputAndOutputFilesAreAvailable;
- (BOOL)isBlockedOnInputOrOutputFileLocks;
- (void)setShouldSynchronizeOnFiles:(BOOL)arg1;
- (BOOL)shouldSynchronizeOnFiles;
- (void)untouch;
- (void)touch;
- (void)fileMayHaveChanged;
- (void)removePredictiveProcessingOutputRecursivelyBecauseOfChangedNode:(id)arg1;
- (void)makeConsumerCommandsOfOutputNodesPerformSelector:(SEL)arg1 withObject:(id)arg2;
- (void)makeOutputNodesPerformSelector:(SEL)arg1 withObject:(id)arg2;
- (void)setCustomToolInfoObject:(id)arg1;
- (id)customToolInfoObject;
- (void)setLaunchPropertyExpansionDictionary:(id)arg1;
- (id)launchPropertyExpansionDictionary;
- (void)didDeactivateInWorkQueue:(id)arg1 didCompleteSuccessfully:(BOOL)arg2;
- (void)propagateSignatureToOutputNodes;
- (void)willActivateInWorkQueue:(id)arg1;
- (void)enqueueOutOfDateCommandsOntoWorkQueue:(id)arg1;
- (void)_2009_enqueueCommandsOntoWorkQueue:(id)arg1 whenceDebugDesc:(id)arg2;
- (BOOL)_2009_doesCommandNeedToRun;
- (BOOL)needsToRun;
- (void)computeStateIfNeeded;
- (BOOL)isUpToDate;
- (void)resetStateRecursively;
- (void)resetState;
- (void)statFileIfNeeded;
- (id)paths;
- (id)path;
//- (CDStruct_7eef4560)signature;
- (void)rerunCommand;
- (int)state;
- (void)writeInputEdgesToGraphVizFile:(struct __sFILE *)arg1;
- (void)writeDefinitionToGraphVizFile:(struct __sFILE *)arg1;
- (id)nameForGraphViz;
- (id)description;
- (id)signatureDescription;
- (id)stateDescription;
- (id)shortNameForDebugging;
- (id)displayString;
- (void)decrementWaitCountsOfDependingNodes;
- (void)incrementWaitCountsOfDependingNodes;
- (void)decrementWaitCount;
- (void)incrementWaitCount;
- (id)instantiatedCommandResultsPostprocessor;
- (id)instantiatedCommandOutputParserWithLogSectionRecorder:(id)arg1;
- (id)descriptionForWorkQueueLog;
- (id)subprocessExtraEnvironmentEntriesForProcessing;
- (id)subprocessWorkingDirectoryForProcessing;
- (id)subprocessCommandLineForProcessing;
- (void)commandInvocationDidEnd:(id)arg1 successfully:(BOOL)arg2;
- (void)commandInvocation:(id)arg1 didEmitBytes:(const char *)arg2 length:(unsigned long long)arg3;
- (void)commandInvocationWillStart:(id)arg1;
- (id)createStartedCommandInvocationInSlot:(unsigned long long)arg1 ofWorkQueueOperation:(id)arg2;
- (void)checkWaitCounts;
- (BOOL)isReadyForProcessing;
- (void)propagateCachedOutputs;
- (BOOL)shouldPropagateCachedOutputs;
- (BOOL)hasCachedOutputs;
- (void)setNeededToRunWhenLastEnqueued:(BOOL)arg1;
- (BOOL)neededToRunWhenLastEnqueued;
- (id)sharedMemoryName;
- (void)noteMightHavePredictiveProcessingOutput;
- (id)predictiveProcessingValiditySignature;
- (id)predictiveProcessingInputFilePath;
- (id)predictiveProcessingCandidateFilePath;
//- (CDStruct_7eef4560)configurationSignature;
//- (CDStruct_7eef4560)inputSignature;
//- (void)_addConfigurationSignatureIngredientsToMD5Context:(struct CC_MD5state_st *)arg1;
- (void)addFilePathToRemove:(id)arg1;
- (id)filePathsToRemove;
- (void)setCaresAboutIncludes:(BOOL)arg1;
- (BOOL)caresAboutIncludes;
- (void)setWorkingDirectoryPath:(id)arg1;
- (id)workingDirectoryPath;
- (void)setExtraSignatureInfo:(id)arg1;
- (id)extraSignatureInfo;
- (void)setEmitEnvVars:(BOOL)arg1;
- (BOOL)emitEnvVars;
- (void)setVariant:(id)arg1;
- (id)variant;
- (void)setArchitecture:(id)arg1;
- (id)architecture;
- (void)addEnvironmentEntriesFromDictionary:(id)arg1;
- (void)addEnvironmentValue:(id)arg1 forKey:(id)arg2;
- (void)setEnvironment:(id)arg1;
- (id)environment;
- (id)commandLine;
- (void)setSpecialEditingOfCommandLineHasBeenPerformed:(BOOL)arg1;
- (BOOL)specialEditingOfCommandLineHasBeenPerformed;
- (void)addBuildMessage:(id)arg1;
- (unsigned long long)transformArgumentsHavingPrefix:(id)arg1 usingFormatString:(id)arg2;
- (unsigned long long)transformArgumentsHavingPrefix:(id)arg1 inRange:(struct _NSRange)arg2 usingFormatString:(id)arg3;
- (void)replaceArgumentAtIndex:(unsigned long long)arg1 withArgument:(id)arg2;
- (void)removeArgumentAtIndex:(unsigned long long)arg1;
- (unsigned long long)indexOfArgumentHavingPrefix:(id)arg1 startingAtIndex:(unsigned long long)arg2;
- (id)argumentAtIndex:(unsigned long long)arg1;
- (unsigned long long)numberOfArguments;
- (void)addArgumentsFromArray:(id)arg1;
- (void)addArguments:(id)arg1;
- (void)addArgument:(id)arg1;
- (id)arguments;
- (void)setCommandPath:(id)arg1;
- (id)commandPath;
- (void)setRuleInfo:(id)arg1;
- (id)ruleInfo;
- (unsigned long long)commandNumber;
- (void)setToolSpecification:(id)arg1;
- (id)toolSpecification;
- (void)_addDependingNode:(id)arg1;
- (void)addOutputNode:(id)arg1;
- (id)outputNodes;
- (void)addInputNode:(id)arg1;
- (id)inputNodes;
- (void)invalidateConfigurationSignature;
- (void)invalidateInputSignature;
- (void)setPhaseNumber:(unsigned long long)arg1;
- (unsigned long long)phaseNumber;
- (id)name;
- (void)addCommandIdentToBuildStateStoreDependencyList;
- (id)buildCommandState;
- (void)setBuildContext:(id)arg1 commandNumber:(unsigned long long)arg2;
- (id)_buildStateId;
- (id)buildContext;
- (void)detachFromOtherGraphObjects;
- (void)dealloc;
- (id)init;
- (id)initWithCommandNumber:(unsigned long long)arg1 ruleInfo:(id)arg2 commandPath:(id)arg3;
- (id)initWithCommandNumber:(unsigned long long)arg1 ruleInfo:(id)arg2 commandPath:(id)arg3 arguments:(id)arg4 environment:(id)arg5;
@end

@interface NSString (TSStringAdditions)
+ (unsigned)TSDefaultCStringEncoding;
+ (void)setTSDefaultCStringEncoding:(unsigned)fp8;
+ (BOOL)isFileUnicode:(id)fp8 fileData:(id)fp12;
+ (BOOL)isFileUTF8WithBOM:(id)fp8 fileData:(id)fp12;
- (id)arrayByParsingAsCommandLineArguments;
- (id)arrayByParsingAsStringList;
- (void)testMacroExpansion;
- (id)namesOfExpandableVariables;
- (id)TS_stringByExpandingVariables:(id)fp8 inRange:(NSRange)fp12 options:(unsigned)fp20;
- (id)TS_stringByExpandingVariables:(id)fp8 options:(unsigned)fp12;
- (id)TS_stringByExpandingEnvironmentVariables;
- (id)stringByDeletingLeadingWhitespace;
- (id)stringByDeletingTrailingWhitespace;
- (id)stringByDeletingAllWhitespace;
- (id)stringByAbbreviatingWithEllipsisInMiddleToLength:(unsigned)fp8;
- (BOOL)isLegalCIdentifier;
- (id)stringByManglingToLegalCIdentifier;
- (id)stringByEscapingForXML;
- (id)stringByUnescapingFromXML;
- (id)initWithContentsOfFile:(id)fp8 defaultCStringEncoding:(unsigned)fp12 getStringEncoding:(unsigned*)fp16;
- (id)initWithUnicodeOrMacOSRomanContentsOfFile:(id)fp8 getStringEncoding:(unsigned*)fp12;
- (id)initWithPotentiallyMalformedUTF8Bytes:(const char*)fp8 length:(unsigned)fp12 stopAtTrailingIncompleteUTF8Sequence:(BOOL)fp16 getUsedLength:(unsigned*)fp20 getNumberOfMalformedSequences:(unsigned*)fp24;
- (void)getLineStartOffsets:(unsigned**)fp8 count:(unsigned*)fp12;
- (NSRange)rangeNotHavingLiteralPrefixAndSuffixInCommonWithRange:(NSRange)fp8 ofString:(id)fp16;
- (BOOL)writeUsingFileSystemEncodingToFile:(id)fp8 atomically:(BOOL)fp12;
@end
