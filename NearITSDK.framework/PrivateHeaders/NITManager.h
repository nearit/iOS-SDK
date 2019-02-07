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

+ (void)setupWithApiKey:(NSString* _Nonnull)apiKey;
+ (NITManager* _Nonnull)defaultManager;
+ (void)setFrameworkName:(NSString* _Nonnull)frameworkName;

- (void)start;
- (void)stop;
- (void)refreshConfigWithCompletionHandler:(void (^_Nullable)(NSError * _Nullable error))completionHandler DEPRECATED_ATTRIBUTE;
- (void)setDeviceTokenWithData:(NSData* _Nonnull)token;
- (BOOL)processRecipeSimpleWithUserInfo:(NSDictionary<NSString*, id> * _Nullable)userInfo;
- (void)sendTrackingWithTrackingInfo:(NITTrackingInfo * _Nullable)trackingInfo event:(NSString* _Nullable)event;
- (void)setUserDataWithKey:(NSString* _Nonnull)key value:(NSString* _Nullable)value completionHandler:(void (^_Nullable)(NSError* _Nullable error))handler DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use setUserData(\"MY_KEY\", value:\"MY_VALUE\")");
- (void)setBatchUserDataWithDictionary:(NSDictionary<NSString*, id>* _Nonnull)valuesDictiornary completionHandler:(void (^_Nullable)(NSError* _Nullable error))handler DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use setUserData(\"MY_KEY\", value:\"MY_VALUE\")");
- (void)setDeferredUserDataWithKey:(NSString * _Nonnull)key value:(NSString * _Nullable)value
DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use setUserDataWithKey(\"MY_KEY\", value:\"MY_VALUE\")");
- (void)setUserDataWithKey:(NSString* _Nonnull)key value:(NSString* _Nullable)value;
- (void)setUserDataWithKey:(NSString* _Nonnull)key multiValue:(NSDictionary<NSString*, NSNumber*>* _Nullable)value;
- (void)sendEventWithEvent:(NITEvent* _Nonnull)event completionHandler:(void (^_Nullable)(NSError* _Nullable error))handler;
- (void)couponsWithCompletionHandler:(void (^ _Nullable)(NSArray<NITCoupon*>* _Nullable, NSError* _Nullable))handler;
- (void)recipesWithCompletionHandler:(void (^_Nullable)(NSArray<NITRecipe*>* _Nullable recipes, NSError * _Nullable error))completionHandler;
- (void)processRecipeWithId:(NSString* _Nonnull)recipeId;
- (BOOL)processRecipeWithUserInfo:(NSDictionary<NSString *,id> * _Nonnull)userInfo completion:(void (^_Nullable)(NITReactionBundle* _Nullable object, NITTrackingInfo * _Nullable trackingInfo, NSError* _Nullable error))completionHandler;
- (BOOL)processRecipeWithResponse:(UNNotificationResponse*)response completion:(void (^_Nullable)(NITReactionBundle* _Nullable object, NITTrackingInfo * _Nullable trackingInfo, NSError* _Nullable error))completionHandler;
- (void)resetProfile DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use resetProfileWithCompletionHandler");
- (void)resetProfileWithCompletionHandler:(void (^_Nonnull)(NSString* _Nullable profileId, NSError* _Nullable error))handler;
- (NSString* _Nullable)profileId DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use profileIdWithCompletionHandler");
- (void)profileIdWithCompletionHandler:(void (^_Nonnull)(NSString* _Nullable profileId, NSError* _Nullable error))handler;
- (void)setProfileId:(NSString * _Nonnull)profileId;
- (void)optOutWithCompletionHandler:(void (^_Nonnull)(BOOL success))handler;
- (void)processCustomTriggerWithKey:(NSString* _Nonnull)key
DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use triggerInAppEventWithKey");
- (void)triggerInAppEventWithKey:(NSString* _Nonnull)key;
- (void)application:(UIApplication* _Nonnull)application performFetchWithCompletionHandler:(void (^_Nonnull)(UIBackgroundFetchResult))completionHandler;
- (void)parseContent:(id _Nonnull)content trackingInfo:(NITTrackingInfo* _Nonnull)trackingInfo contentDelegate:(id<NITContentDelegate> _Nonnull)contentDelegate;
- (BOOL)application:(UIApplication* _Nonnull)application openURL:(NSURL* _Nonnull)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id>* _Nullable)options;
- (void)historyWithCompletion:(void(^_Nonnull)(NSArray<NITHistoryItem*>* _Nullable items, NSError* _Nullable error))completion;
- (void)updateWithNotification:(UNNotification* _Nonnull)notification;
- (void)markNotificationHistoryAsOld;

@end
