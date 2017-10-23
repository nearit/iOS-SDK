//
//  NITFeedbackEvent.h
//  NearITSDK
//
//  Created by Francesco Leoni on 31/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITEvent.h"

@class NITFeedback;
@class NITJSONAPI;
@class NITConfiguration;

@interface NITFeedbackEvent : NITEvent

@property (nonatomic, strong) NSString * _Nonnull ID;
@property (nonatomic, strong) NSString * _Nonnull recipeId;

- (instancetype _Nonnull)initWithFeedback:(NITFeedback* _Nonnull)feedback rating:(NSInteger)rating comment:(NSString* _Nonnull)comment;
- (NITJSONAPI* _Nullable)toJsonAPI:(NITConfiguration* _Nonnull)configuration;

@end
