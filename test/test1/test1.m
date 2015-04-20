// **********************************************************************
//
// Copyright (c) 2008-2015 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "slice1.h"

#import <objc/Ice/Ice.h>
#import <objc/IceStorm/IceStorm.h>
#import <objc/IceGrid/IceGrid.h>
#import <objc/Glacier2/Glacier2.h>

@interface test1 : XCTestCase

@end

@implementation test1

- (void)testProxy {
    XCTAssert(YES, @"Pass");
    [Test1IntfPrx uncheckedCast:nil];
}

- (void) testServices {
    [ICESTORMTopicPrx uncheckedCast:nil];
    [GLACIER2PermissionsVerifierPrx uncheckedCast:nil];
    [ICEGRIDAdminPrx uncheckedCast:nil];
}

@end
