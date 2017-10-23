//
//  NITUTils.h
//  NearITSDK
//
//  Created by Francesco Leoni on 15/03/17.
//  Copyright © 2017 NearIT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "NITConstants.h"

@interface NITUtils : NSObject

+ (NSString* _Nonnull)fetchAppIdFromApiKey:(NSString* _Nonnull)apiKey;
+ (NSString* _Nonnull)stringFromRegionEvent:(NITRegionEvent)event;
+ (NSString* _Nonnull)stringTagFromRegionEvent:(NITRegionEvent)event;
+ (NSString* _Nonnull)stringFromBluetoothState:(CBManagerState)state;
+ (NSString* _Nonnull)generateUUID;

@end
