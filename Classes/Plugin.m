// **********************************************************************
//
// Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
//
// This copy of Ice Touch is licensed to you under the terms described
// in the ICE_TOUCH_LICENSE file included in this distribution.
//
// **********************************************************************

#import <Foundation/Foundation.h>

#define ICE_TOUCH_PLUGIN_VERSION "1.0.0"

@interface IceTouchPlugin : NSObject {
}
@end

@implementation IceTouchPlugin
+(void)pluginDidLoad:(NSBundle *)plugin
{
    // Only print the version of the Xcode plugin if we're loaded from
    // Xcode (the plugin can also be loaded by xcodebuild).
    if([[[NSBundle mainBundle] infoDictionary][@"CFBundleName"] isEqual:@"Xcode"])
    {
        NSLog(@"IceTouchPlugin %s loaded", ICE_TOUCH_PLUGIN_VERSION);
    }
}
@end
