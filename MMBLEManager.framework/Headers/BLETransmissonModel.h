//
//  BLETransmissonModel.h
//  Paperang
//
//  Created by hoho on 2016/12/20.
//  Copyright © 2016年 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MM_PRT_DEFINE.h"

@interface BLETransmissonModel : NSObject

@property (assign) PRT_BLE_TYPE type;

@property (assign) uint8_t packageID;

@property (assign) uint16_t length;

@property (strong, nonatomic) NSData *data;

@property (assign) uint32_t crc;

+ (BLETransmissonModel *)modelWithData:(NSData *)data withProtocolID:(NSInteger)protocolId;

@end
