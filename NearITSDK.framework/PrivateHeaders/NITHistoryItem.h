//
//  NITHistoryItem.h
//  NearITSDK
//
//  Created by francesco.leoni on 21/02/18.
//  Copyright © 2018 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NITTrackingInfo;
@class NITReactionBundle;

@interface NITHistoryItem : NSObject

@property (nonatomic, strong) NITTrackingInfo* _Nonnull trackingInfo;
@property (nonatomic, strong) NITReactionBundle* _Nonnull reactionBundle;
@property (nonatomic, readonly) NSDate* _Nonnull date;
@property (nonatomic) NSTimeInterval timestamp;
@property (nonatomic) BOOL read;
@property (nonatomic) BOOL isNew;

@end
