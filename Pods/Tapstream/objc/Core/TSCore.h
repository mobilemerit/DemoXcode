#pragma once
#import <Foundation/Foundation.h>
#import "TSEvent.h"
#import "TSDelegate.h"
#import "TSPlatform.h"
#import "TSCoreListener.h"
#import "TSHit.h"
#import "TSResponse.h"
#import "TSConfig.h"
#import "TSAppEventSource.h"

#if TEST_IOS || TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#define kTSPlatform @"iOS"
#else
#define kTSPlatform @"Mac"
#endif

@interface TSCore : NSObject {
@private
	id<TSDelegate> del;
	id<TSPlatform> platform;
	id<TSCoreListener> listener;
	id<TSAppEventSource> appEventSource;
	TSConfig *config;
	NSString *accountName;
	NSMutableString *postData;
	NSMutableSet *firingEvents;
	NSMutableSet *firedEvents;
	NSString *failingEventId;
	NSString *appName;
	int delay;
}

- (id)initWithDelegate:(id<TSDelegate>)delegate platform:(id<TSPlatform>)platform listener:(id<TSCoreListener>)listener appEventSource:(id<TSAppEventSource>)appEventSource accountName:(NSString *)accountName developerSecret:(NSString *)developerSecret config:(TSConfig *)config;
#if TEST_IOS || TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
- (void)attachIdfaIfNotPresent:(TSConfig *)configVal;
#endif
- (void)start;
- (void)fireEvent:(TSEvent *)event;
- (void)fireHit:(TSHit *)hit completion:(void(^)(TSResponse *))completion;
- (void)getConversionData:(void(^)(NSData *))completion;
- (int)getDelay;
- (NSMutableString *)postData;

@end
