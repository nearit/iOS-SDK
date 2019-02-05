//
//  NITNotificationHistoryManager.h
//  NearITSDK
//
//  Created by francesco.leoni on 22/02/18.
//  Copyright © 2018 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NITNetworkManaging.h"
// #import "NITNotificationUpdateDelegate.h"

@class NITConfiguration;
@class NITDateManager;
@class NITReachability;
@class NITReactionItem;
@class NITTrackingInfo;
@class NITHistoryItem;
@class NITNotificationUpdateState;
@class NITReactionsManager;
@class NITCacheManager;
@class NITNotificationHistoryRepo;
@protocol NITNotificationUpdateDelegate;

extern NSErrorDomain _Nonnull const NITNotificationHistoryErrorDomain;

@interface NITNotificationHistoryManager : NSObject

@property (nonatomic, weak) id<NITNotificationUpdateDelegate> _Nullable delegate;

- (instancetype _Nonnull)initWithDateManager:(NITDateManager* _Nonnull)dateManager internetReachability:(NITReachability* _Nonnull)internetReachability state:(NITNotificationUpdateState* _Nonnull)state repo:(NITNotificationHistoryRepo* _Nonnull)repo;

- (void)addItemToHistory:(NITReactionItem* _Nullable)reactionItem trackingInfo:(NITTrackingInfo* _Nullable)trackingInfo notificationBody:(NSString* _Nullable)notificationBody trackingEvent:(NSString* _Nullable)trackingEvent;
- (void)markAllAsNew;
- (void)notificationHistoryWithCompletion:(void(^_Nonnull)(NSArray<NITHistoryItem*>* _Nullable items, NSError* _Nullable error))completion;
- (void)clear;
- (void)updateHistoryListeners;

+ (NITNotificationHistoryManager* _Nonnull)obtainWithNetworkManager:(id<NITNetworkManaging> _Nonnull)networkManager reactionsManager:(NITReactionsManager* _Nonnull)reactionsManager cacheManager:(NITCacheManager* _Nonnull)cacheManager internetReachability:(NITReachability* _Nonnull)internetReachability configuration:(NITConfiguration* _Nonnull)configuration;

@end
