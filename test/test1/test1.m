//
//  test1.m
//  test1
//
//  Created by Benoit Foucher on 24/03/2015.
//
//

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
