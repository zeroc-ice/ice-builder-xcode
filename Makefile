# **********************************************************************
#
# Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
#
# This copy of Ice Touch is licensed to you under the terms described
# in the ICE_TOUCH_LICENSE file included in this distribution.
#
# **********************************************************************

ICE_HOME 		?= /usr/local/opt/ice
ICE_TOUCH_HOME 	?= /usr/local/opt/icetouch

TESTS			= test1 test2 test3 test4

all::
	xcodebuild build

install::
	xcodebuild install

test::
	@if [ ! -d $(ICE_HOME) ]; then echo "error: tests require Ice to be installed in $(ICE_HOME)"; exit 1; fi
	@if [ ! -d $(ICE_TOUCH_HOME) ]; then echo "error: tests require IceTouch to be installed in $(ICE_TOUCH_HOME)"; exit 1; fi
	@for test in $(TESTS); \
	do \
	    echo "Running $$subdir..."; \
	    ( cd test && xcodebuild -scheme $$test ICE_HOME=$(ICE_HOME) ICE_TOUCH_HOME=$(ICE_TOUCH_HOME) test ) || exit 1; \
	done
