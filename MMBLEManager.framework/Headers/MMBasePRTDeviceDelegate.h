//
//  MMBasePRTDeviceDelegate.h
//  Paperang
//
//  Created by hoho on 2019/7/17.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import "MMDeviceDelegate.h"
#import "MMDeviceProtocolDefine.h"
@class BLETransmissonModel;

NS_ASSUME_NONNULL_BEGIN

@interface MMBasePRTDeviceDelegate : MMDeviceDelegate <PaperangPRTProtocol>

@property (assign, nonatomic) NSInteger feedlineLength;

@property (assign, nonatomic) NSInteger MTU;

@property (assign, nonatomic) NSInteger credit;

@property (assign, nonatomic) uint32_t crcKey;

@property (assign) NSInteger protocolId;

@property (strong, nonatomic) NSData *hfmTreeData;

@property (assign) NSInteger packageLength;

@property (assign) uint8_t packageID;

- (NSData *)compressData:(NSData *)data;

//pack data
- (NSArray *)packFirstData:(NSData *)firstData;
- (NSArray *)packImageData:(NSData *)imageData;
- (NSArray *)packImageData:(NSData *)imageData withLength:(uint16_t)length;
- (NSArray *)packCompressImageData:(NSData *)imageData;
- (NSArray *)packCompressImageData:(NSData *)imageData withLength:(uint16_t)length;
- (NSArray *)packFirmware:(NSData *)firmware;
- (NSArray *)feedLine;
- (NSArray *)feedLineWithLength:(uint16_t)length;
- (NSArray *)feedLineToHead;
- (NSArray *)setGrayScale:(uint16_t)grayScale;
- (NSArray *)setDensity:(uint8_t)density;
- (NSArray *)setVelocity:(uint8_t)velocity;
- (NSArray *)setFactoryStatus:(uint8_t)status;
- (NSArray *)setPaperMode:(uint8_t)mode;
- (NSArray *)setAutoOffTime:(uint16_t)time;
- (NSArray *)searchType:(PRT_BLE_TYPE)type;
- (NSArray *)searchType:(PRT_BLE_TYPE)type dataLen:(uint16_t)dataLength;
- (NSArray *)setGapLength:(uint8_t)gapLen;
- (NSArray *)setPrinterRestoreDefault;
- (NSArray *)setBluetoothOTAModel;
- (NSArray *)setValueType:(uint8_t)type
                    value:(uint16_t)value
                   length:(uint16_t)length;
- (NSArray *)operateWithCommand:(Byte)command
                           Data:(NSData *)data
                         andKey:(uint32_t)key;

- (NSArray <NSData *> *)getSeparatorDatasWithWithCommand:(Byte)command
                                                    Data:(NSData *)data
                                                  andKey:(uint32_t)key;
- (NSArray *)getNormalDataWithType:(uint8_t)type
                             value:(uint8_t *)value
                            length:(uint16_t)length
                               key:(uint32_t)key;
- (NSArray *)feedLineWithLength:(uint16_t)length Key:(uint32_t)key ;
- (NSArray *)getDatasWithWithType:(uint8_t)type
                             data:(NSData *)data
                              key:(uint32_t)key;

//unpack data
- (void)unpackData:(NSData *)data
          complete:(void (^)(MMDeviceManagerOpModel *op))complete;
- (void)unpackBTData:(NSData *)data
          complete:(void (^)(MMDeviceManagerOpModel *op))complete;

- (NSArray *)startBTOTAMode;
- (NSArray *)eraseBTFlashWithData:(NSData *)data;
- (BOOL)verifyBTUpdateData:(NSData *)data;
- (NSArray *)unpackBTUpdateData:(NSData *)data;
- (NSArray *)operateBTUpdateData:(NSData *)data;

- (NSArray *)operateBTData:(NSData *)data;


- (void)handleDataModel:(BLETransmissonModel *)model withModel:(MMDeviceManagerOpModel *)m;

- (NSData *)packSetPaperMode:(PrintPaperType)type;
- (NSData *)getPackImageData:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
