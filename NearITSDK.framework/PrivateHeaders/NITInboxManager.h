//
//  NITInboxManager.h
//  NearITSDK
//
//  Created by francesco.leoni on 22/02/18.
//  Copyright © 2018 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NITNetworkManaging.h"

@class NITInboxApi;
@class NITPushHistory;
@class NITInboxItemResolver;
@class NITInboxHistory;
@class NITDateManager;
@class NITReachability;
@class NITReactionItem;
@class NITTrackingInfo;
@class NITInboxItem;
@class NITReactionsManager;
@class NITCacheManager;
@class NITReachability;

extern NSErrorDomain _Nonnull const NITInboxErrorDomain;

@interface NITInboxManager : NSObject

- (instancetype _Nonnull)initWithApi:(NITInboxApi* _Nonnull)api pushHistory:(NITPushHistory* _Nonnull)pushHistory itemResolver:(NITInboxItemResolver* _Nonnull)itemResolver inboxHistory:(NITInboxHistory* _Nonnull)inboxHistory dateManager:(NITDateManager* _Nonnull)dateManager internetReachability:(NITReachability* _Nonnull)internetReachability;

- (void)addPushMessageWithDeliveryID:(NSString* _Nonnull)deliveryID;
- (void)addItemToInbox:(NITReactionItem* _Nullable)reactionItem trackingInfo:(NITTrackingInfo* _Nullable)trackingInfo notificationBody:(NSString* _Nullable)notificationBody trackingEvent:(NSString* _Nullable)trackingEvent;
- (void)inboxWithCompletion:(void(^_Nonnull)(NSArray<NITInboxItem*>* _Nullable items, NSError* _Nullable error))completion;
- (void)clear;

+ (NITInboxManager* _Nonnull)obtainWithNetworkManager:(id<NITNetworkManaging> _Nonnull)networkManager reactionsManager:(NITReactionsManager* _Nonnull)reactionsManager cacheManager:(NITCacheManager* _Nonnull)cacheManager internetReachability:(NITReachability* _Nonnull)internetReachability;

@end
