//
//  NITNotificationHistoryManager.h
//  NearITSDK
//
//  Created by francesco.leoni on 22/02/18.
//  Copyright © 2018 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NITNetworkManaging.h"

@class NITHistoryApi;
@class NITHistoryItemResolver;
@class NITLocalHistory;
@class NITHistoryMerger;
@class NITConfiguration;
@class NITDateManager;
@class NITReachability;
@class NITReactionItem;
@class NITTrackingInfo;
@class NITHistoryItem;
@class NITReactionsManager;
@class NITCacheManager;
@class NITReachability;

extern NSErrorDomain _Nonnull const NITNotificationHistoryErrorDomain;

@interface NITNotificationHistoryManager : NSObject

- (instancetype _Nonnull)initWithApi:(NITHistoryApi* _Nonnull)api itemResolver:(NITHistoryItemResolver* _Nonnull)itemResolver localHistory:(NITLocalHistory* _Nonnull)localHistory dateManager:(NITDateManager* _Nonnull)dateManager internetReachability:(NITReachability* _Nonnull)internetReachability historyMerger:(NITHistoryMerger* _Nonnull)historyMerger;

- (void)addItemToHistory:(NITReactionItem* _Nullable)reactionItem trackingInfo:(NITTrackingInfo* _Nullable)trackingInfo notificationBody:(NSString* _Nullable)notificationBody trackingEvent:(NSString* _Nullable)trackingEvent;
- (void)notificationHistoryWithCompletion:(void(^_Nonnull)(NSArray<NITHistoryItem*>* _Nullable items, NSError* _Nullable error))completion;
- (void)clear;

+ (NITNotificationHistoryManager* _Nonnull)obtainWithNetworkManager:(id<NITNetworkManaging> _Nonnull)networkManager reactionsManager:(NITReactionsManager* _Nonnull)reactionsManager cacheManager:(NITCacheManager* _Nonnull)cacheManager internetReachability:(NITReachability* _Nonnull)internetReachability configuration:(NITConfiguration* _Nonnull)configuration;

@end
