//
//  NITConstants.h
//  NearITSDK
//
//  Created by Francesco Leoni on 23/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NITRegionEvent) {
    NITRegionEventEnterArea,
    NITRegionEventLeaveArea,
    NITRegionEventImmediate,
    NITRegionEventNear,
    NITRegionEventFar,
    NITRegionEventEnterPlace,
    NITRegionEventLeavePlace,
    NITRegionEventUnknown
};

extern NSErrorDomain const NITManagerErrorDomain;
extern NSErrorDomain const NITUserProfileErrorDomain;
extern NSErrorDomain const NITInstallationErrorDomain;
extern NSErrorDomain const NITReactionErrorDomain;
extern NSErrorDomain const NITRecipeErrorDomain;
extern NSErrorDomain const NITNotificationProcessorDomain;
extern NSErrorDomain const NITNetowkrErrorDomain;
extern NSErrorDomain const NITTrackSenderErrorDomain;

extern NSString* const ISO8601DateFormatMilliseconds;

extern NSString* const NITHttpStatusCode;

extern NSString* const NITNotTrack; // String to put in the recipeId field for deny a recipe tracking
