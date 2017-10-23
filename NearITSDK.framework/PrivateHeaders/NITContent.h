//
//  NITContent.h
//  NearITSDK
//
//  Created by Francesco Leoni on 24/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import "NITReactionBundle.h"

@class NITImage;
@class NITAudio;
@class NITUpload;
@class NITContentLink;

@interface NITContent : NITReactionBundle<NSCoding>

@property (nonatomic, strong) NSArray<NITImage*> * _Nullable images DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("You should use 'image' attribute");
@property (nonatomic, strong) NSString * _Nullable videoLink DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Unused");
@property (nonatomic, strong) NITAudio * _Nullable audio DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Unused");
@property (nonatomic, strong) NITUpload * _Nullable upload DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Unused");

@property (nonatomic, strong) NSString* _Nullable title;
@property (nonatomic, strong) NSString* _Nullable content;
@property (nonatomic, readonly) NITImage* _Nullable image;
@property (nonatomic, readonly) NITContentLink* _Nullable link;

@end
