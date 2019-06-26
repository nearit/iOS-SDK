//
//  NITNotificationUpdateDelegate.h
//  NearITSDK
//
//  Created by Cattaneo Stefano on 29/01/2019.
//  Copyright © 2019 NearIT. All rights reserved.
//
#import "NITHistoryItem.h"

@protocol NITNotificationUpdateDelegate <NSObject>

- (void)historyUpdatedWithItems:(NSArray<NITHistoryItem*>* _Nullable) items;

@end
