//
//  test3.m
//  test3
//
//  Created by Benoit Foucher on 25/03/2015.
//
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import <objc/Ice/Ice.h>
#import <slice/slice2.h>

@interface test3 : XCTestCase

@end

@implementation test3

- (void)testProxy {
    [Test1IntfPrx uncheckedCast:nil];
}

- (void)testStreaming {
    @try {
        id<ICECommunicator> com = [ICEUtil createCommunicator];
        id<ICEOutputStream> os = [ICEUtil createOutputStream:com];
        Test1Op* op = [Test1Op op:@"test"];
        [os writeObject:op];
        [os finished];
        [com destroy];
    } @catch (NSException *ex) {
        XCTAssert(NO, @"Failure: %@", ex);
    }
}

@end
