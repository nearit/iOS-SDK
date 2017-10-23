//
//  NITContentLink.h
//  NearITSDK
//
//  Created by francesco.leoni on 04/10/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NITContentLink : NSObject<NSCoding>

@property (nonatomic, strong) NSURL *url;
@property (nonatomic, strong) NSString *label;

@end
