//
//  NITLog.h
//  NearITSDK
//
//  Created by Francesco Leoni on 13/04/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NITLogger.h"

typedef NS_ENUM(NSInteger, NITLogLevel) {
    NITLogLevelVerbose = 0,
    NITLogLevelDebug = 1,
    NITLogLevelInfo = 2,
    NITLogLevelWarning = 3,
    NITLogLevelError = 4
};

@interface NITLog : NSObject

+ (void)setLogger:(id<NITLogger> _Nonnull)logger;
+ (void)setLevel:(NITLogLevel)level;
+ (void)setLogEnabled:(BOOL)enabled;

@end

void NITLogV(NSString * _Nonnull tag, NSString * _Nonnull format, ...);
void NITLogD(NSString * _Nonnull tag, NSString * _Nonnull format, ...);
void NITLogI(NSString * _Nonnull tag, NSString * _Nonnull format, ...);
void NITLogW(NSString * _Nonnull tag, NSString * _Nonnull format, ...);
void NITLogE(NSString * _Nonnull tag, NSString * _Nonnull format, ...);
