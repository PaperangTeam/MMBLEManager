//
//  MMDeviceManagerOpModel.h
//  Paperang
//
//  Created by hoho on 2019/7/11.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MMDeviceManagerOpType) {
    MMDeviceManagerOpTypeNone = 0,
    MMDeviceManagerOpTypeAssign = 1 << 0,
    MMDeviceManagerOpTypeAssignWithDictionary = 1 << 1,
    MMDeviceManagerOpTypeCommand = 1 << 2,
    MMDeviceManagerOpTypeNotification = 1 << 3,
    MMDeviceManagerOpTypeFirmwareUpdateSuccess = 1 << 4,
    MMDeviceManagerOpTypeException = 1 << 5,
    MMDeviceManagerOpTypePendingCommand = 1 << 6,
    MMDeviceManagerOpTypePendingCommandAndValues = 1 << 7,
    MMDeviceManagerOpTypeConnectSuccess = 1 << 7
};

NS_ASSUME_NONNULL_BEGIN

@interface MMDeviceManagerOpModel : NSObject

@property (assign, nonatomic) MMDeviceManagerOpType op;

@property (copy, nonatomic) NSDictionary *valueInfo;

@property (strong, nonatomic) NSData *cmdData;

@property (strong, nonatomic) NSNotification *notification;

@property (assign, nonatomic) uint16_t status;

@property (assign, nonatomic) NSInteger pendingCommand;

@property (strong, nonatomic) NSArray *pendingValues;

@end

NS_ASSUME_NONNULL_END
