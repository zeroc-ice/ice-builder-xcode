// **********************************************************************
//
// Copyright (c) 2008-2016 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

// Disable verify macro which conflicts with Ice C++ headers.
#define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#include <Ice/Ice.h>
#include <IceGrid/IceGrid.h>
#include <IceStorm/IceStorm.h>
#include <Glacier2/Glacier2.h>

#include <Ice/SliceChecksums.h>

#include <slice/slice2.h>


@interface test2 : XCTestCase

@end

@implementation test2

- (void)testProxy {
    Test1::IntfPrx::uncheckedCast(Test1::IntfPrx());
}

- (void)testStreaming {
    try {
        Ice::CommunicatorPtr com = Ice::initialize();
        Ice::OutputStreamPtr os = Ice::createOutputStream(com);
        Test1::OpPtr op = new Test1::Op("test");
        os->write(op);
        com->destroy();
    } catch (const std::exception& ex) {
        XCTAssert(NO, @"Failure: %@", [NSString stringWithUTF8String:ex.what()]);
    }
}

-(void)testChecksums {
    Ice::SliceChecksumDict checksums = Ice::sliceChecksums();
    XCTAssert(checksums.find("::Test1::Intf") != checksums.end(), @"Pass");
}

- (void)testServices {
    IceStorm::TopicPrx::uncheckedCast(IceStorm::TopicPrx());
    Glacier2::RouterPrx::uncheckedCast(Glacier2::RouterPrx());
    IceGrid::AdminPrx::uncheckedCast(IceGrid::AdminPrx());
}

@end
