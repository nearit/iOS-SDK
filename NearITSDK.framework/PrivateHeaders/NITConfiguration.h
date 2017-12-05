//
//  NITConfiguration.h
//  NearITSDK
//
//  Created by Francesco Leoni on 14/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NITConfiguration;

extern NSTimeInterval const NITConfigurationDefaultSchedulePeriod;

@protocol NITConfigurationDelegate<NSObject>

- (void)configurationDidOptOut:(NITConfiguration* _Nonnull)configuration;

@end

@interface NITConfiguration : NSObject

@property (nonatomic, strong) id<NITConfigurationDelegate> _Nullable delegate;

+ (NITConfiguration* _Nonnull)defaultConfiguration;
- (instancetype _Nonnull)initWithUserDefaults:(NSUserDefaults* _Nonnull)userDefaults;

- (NSString* _Nonnull)paramKeyWithKey:(NSString* _Nonnull)key;
- (NSString* _Nullable)apiKey;
- (NSString* _Nullable)appId;
- (NSString* _Nullable)profileId;
- (void)setApiKey:(NSString * _Nonnull)apiKey;
- (void)setAppId:(NSString * _Nonnull)appId;
- (void)setProfileId:(NSString * _Nullable)profileId;
- (NSString* _Nullable)installationId;
- (void)setInstallationId:(NSString* _Nullable)installationId;
- (NSString * _Nullable)deviceToken;
- (void)setDeviceToken:(NSString * _Nonnull)deviceToken;
- (BOOL)isOptOut;
- (void)setOptOut:(BOOL)optOut;
- (NSTimeInterval)schedulePeriod;
- (void)setSchedulePeriod:(NSTimeInterval)schedulePeriod;
- (void)clear;

@end
