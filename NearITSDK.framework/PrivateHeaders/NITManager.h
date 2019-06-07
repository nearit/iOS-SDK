//
//  NITManager.h
//  NearITSDK
//
//  Created by Francesco Leoni on 14/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NITContentDelegate.h"
#import "NITNotificationHistoryManager.h"
#import <MessageUI/MessageUI.h>
#import <UserNotifications/UserNotifications.h>

@class NITRecipesManager;
@class NITRecipe;
@class NITManager;
@class NITEvent;
@class NITCoupon;
@class UNNotificationResponse;
@class UILocalNotification;
@class NITTrackingInfo;
@class NITReactionBundle;
@class NITHistoryItem;

@protocol NITManaging <NSObject>

- (void)recipesManager:(NITRecipesManager* _Nonnull)recipesManager gotRecipe:(NITRecipe* _Nonnull)recipe trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;

@end

@protocol NITManagerDelegate <NSObject>

- (void)manager:(NITManager* _Nonnull)manager eventWithContent:(id _Nonnull)content trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;
- (void)manager:(NITManager* _Nonnull)manager eventFailureWithError:(NSError* _Nonnull)error;

@optional

- (void)manager:(NITManager* _Nonnull)manager alertWantsToShowContent:(id _Nonnull)content trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo;

@end

@interface NITManager : NSObject

@property (nonatomic, weak) id<NITManagerDelegate> _Nullable delegate;
@property (nonatomic, weak) id<NITNotificationUpdateDelegate> _Nullable notificationDelegate;
@property (nonatomic) BOOL showBackgroundNotification;
@property (nonatomic) BOOL showForegroundNotification;

// Setup
+ (void)setupWithApiKey:(NSString* _Nonnull)apiKey;
+ (NITManager* _Nonnull)defaultManager;
+ (void)setFrameworkName:(NSString* _Nonnull)frameworkName;
- (BOOL)application:(UIApplication* _Nonnull)application openURL:(NSURL* _Nonnull)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id>* _Nullable)options;
- (void)application:(UIApplication* _Nonnull)application performFetchWithCompletionHandler:(void (^_Nonnull)(UIBackgroundFetchResult))completionHandler;
- (void)setDeviceTokenWithData:(NSData* _Nonnull)token;

// Profile
- (void)setUserDataWithKey:(NSString* _Nonnull)key value:(NSString* _Nullable)value;
- (void)setUserDataWithKey:(NSString* _Nonnull)key multiValue:(NSDictionary<NSString*, NSNumber*>* _Nullable)value;
- (void)setProfileId:(NSString * _Nonnull)profileId;
- (void)getUserDataWithCompletionHandler:(void (^ _Nonnull)(NSDictionary<NSString*, id>* _Nullable userData, NSError* _Nullable error))handler;
- (void)profileIdWithCompletionHandler:(void (^_Nonnull)(NSString* _Nullable profileId, NSError* _Nullable error))handler;
- (void)resetProfileWithCompletionHandler:(void (^_Nonnull)(NSString* _Nullable profileId, NSError* _Nullable error))handler;
- (void)optOutWithCompletionHandler:(void (^_Nonnull)(BOOL success))handler;
- (void)resetProfile DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use resetProfileWithCompletionHandler");
- (void)setDeferredUserDataWithKey:(NSString * _Nonnull)key value:(NSString * _Nullable)value
DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use setUserDataWithKey(\"MY_KEY\", value:\"MY_VALUE\")");
- (void)setUserDataWithKey:(NSString* _Nonnull)key value:(NSString* _Nullable)value completionHandler:(void (^_Nullable)(NSError* _Nullable error))handler DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use setUserData(\"MY_KEY\", value:\"MY_VALUE\")");
- (void)setBatchUserDataWithDictionary:(NSDictionary<NSString*, id>* _Nonnull)valuesDictiornary completionHandler:(void (^_Nullable)(NSError* _Nullable error))handler DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use setUserData(\"MY_KEY\", value:\"MY_VALUE\")");
- (NSString* _Nullable)profileId DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use profileIdWithCompletionHandler");

// Radar
- (void)start;
- (void)stop;

// Content
- (void)userNotificationCenter:(UNUserNotificationCenter* _Nonnull)center willPresent:(UNNotification* _Nonnull)notification withCompletionHandler:(void (^_Nonnull)(UNNotificationPresentationOptions options))handler;
- (BOOL)getContentFrom:(UNNotificationResponse* _Nonnull)response completion:(void (^_Nullable)(NITReactionBundle* _Nullable object, NITTrackingInfo * _Nullable trackingInfo, NSError* _Nullable error))completionHandler;
- (BOOL)processRecipeWithResponse:(UNNotificationResponse* _Nonnull)response completion:(void (^_Nullable)(NITReactionBundle* _Nullable object, NITTrackingInfo * _Nullable trackingInfo, NSError* _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use getContentFrom");
- (void)couponsWithCompletionHandler:(void (^ _Nullable)(NSArray<NITCoupon*>* _Nullable, NSError* _Nullable))handler;

// Manual configuration
- (BOOL)processRecipeSimpleWithUserInfo:(NSDictionary<NSString*, id> * _Nullable)userInfo;
- (void)recipesWithCompletionHandler:(void (^_Nullable)(NSArray<NITRecipe*>* _Nullable recipes, NSError * _Nullable error))completionHandler;
- (void)processRecipeWithId:(NSString* _Nonnull)recipeId;
- (BOOL)processRecipeWithUserInfo:(NSDictionary<NSString *,id> * _Nonnull)userInfo completion:(void (^_Nullable)(NITReactionBundle* _Nullable object, NITTrackingInfo * _Nullable trackingInfo, NSError* _Nullable error))completionHandler;
- (void)refreshConfigWithCompletionHandler:(void (^_Nullable)(NSError * _Nullable error))completionHandler DEPRECATED_ATTRIBUTE;
- (void)sendTrackingWithTrackingInfo:(NITTrackingInfo * _Nullable)trackingInfo event:(NSString* _Nullable)event;
- (void)sendEventWithEvent:(NITEvent* _Nonnull)event completionHandler:(void (^_Nullable)(NSError* _Nullable error))handler;

// Custom trigger
- (void)processCustomTriggerWithKey:(NSString* _Nonnull)key
DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use triggerInAppEventWithKey");
- (void)triggerInAppEventWithKey:(NSString* _Nonnull)key;

// Util
- (void)parseContent:(id _Nonnull)content trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo contentDelegate:(id<NITContentDelegate> _Nonnull)contentDelegate;

// Notification History
- (void)historyWithCompletion:(void(^_Nonnull)(NSArray<NITHistoryItem*>* _Nullable items, NSError* _Nullable error))completion;
- (void)updateWithNotification:(UNNotification* _Nonnull)notification;
- (void)markNotificationHistoryAsOld;

@end
