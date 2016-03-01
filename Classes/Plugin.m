// **********************************************************************
//
// Copyright (c) 2008-2016 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#import <Foundation/Foundation.h>

#define ICE_BUILDER_VERSION "2.1.0"

@interface IceBuilder : NSObject {
}
@end

@implementation IceBuilder
+(void)pluginDidLoad:(NSBundle *)plugin
{
    // Only print the version of the Xcode plugin if we're loaded from
    // Xcode (the plugin can also be loaded by xcodebuild).
    if([[[NSBundle mainBundle] infoDictionary][@"CFBundleName"] isEqual:@"Xcode"])
    {
        NSLog(@"IceBuilder %s loaded", ICE_BUILDER_VERSION);
    }
}
@end
