//
//  NITRecipe.h
//  NearITSDK
//
//  Created by Francesco Leoni on 22/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITResource.h"

extern NSString* _Nonnull const NITRecipeNotified DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("You should use 'NITRecipeReceived' constant");
extern NSString* _Nonnull const NITRecipeReceived;
extern NSString* _Nonnull const NITRecipeEngaged DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("You should use 'NITRecipeOpened' constant");
extern NSString* _Nonnull const NITRecipeOpened;
extern NSString* _Nonnull const NITRecipeCtaTapped;

@class NITPulseBundle;

@interface NITRecipe : NITResource<NSCoding>

@property (nonatomic, strong) NSString * _Nullable name;
@property (nonatomic, strong) NSDictionary<NSString*, id> * _Nullable notification;
@property (nonatomic, strong) NSDictionary<NSString*, id> * _Nullable labels;
@property (nonatomic, strong) NSArray<NSDictionary<NSString*, id>*> * _Nullable scheduling;
@property (nonatomic, strong) NSDictionary<NSString*, id> * _Nullable cooldown;
@property (nonatomic, strong) NSString * _Nonnull pulsePluginId;
@property (nonatomic, strong) NSString * _Nonnull reactionPluginId;
@property (nonatomic, strong) NSString * _Nonnull reactionBundleId;
@property (nonatomic, strong) NSArray<NSString*> * _Nullable tags;
@property (nonatomic, strong) NITResource * _Nonnull pulseBundle;
@property (nonatomic, strong) NITResource * _Nonnull pulseAction;
@property (nonatomic, strong) NITResource * _Nonnull reactionAction;
@property (nonatomic, strong) NITResource * _Nonnull reactionBundle;

- (BOOL)isEvaluatedOnline;
- (BOOL)isForeground;
- (NSString* _Nullable)notificationTitle;
- (NSString* _Nullable)notificationBody;

@end
