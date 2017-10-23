//
//  NITUpload.h
//  NearITSDK
//
//  Created by Francesco Leoni on 13/04/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <NearITSDK/NearITSDK.h>

@interface NITUpload : NITResource<NSCoding>

@property (nonatomic, strong) NSDictionary<NSString*, NSString*>* _Nonnull upload;

- (NSURL* _Nullable)url;

@end
