//
//  MMDeviceDelegate.h
//  Paperang
//
//  Created by hoho on 2019/7/9.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMDeviceProtocolDefine.h"
#import "MMDeviceManagerOpModel.h"
#import "MMBluetoothDeviceModel.h"

typedef NS_ENUM(NSUInteger, MMDeviceDelegateRegisterState) {
    MMDeviceDelegateStateUnregistered, ///< 未注册
    MMDeviceDelegateStateRegistered   ///< 已注册
};

@class MMThermalDeviceHandle;
NS_ASSUME_NONNULL_BEGIN

@interface MMDeviceDelegate : MMBluetoothDeviceModel <PaperangBaseProtocol>

@property (nonatomic,assign) BOOL isNeedRegist;

@property (assign, nonatomic) NSInteger printWidth;

@property (assign, nonatomic) NSInteger imageWidth;

// print target width
@property (assign, nonatomic) NSInteger targetWidth;

/// 注册状态( 用于判断是否已经在我们应用中注册成功)
@property (assign, nonatomic) MMDeviceDelegateRegisterState registerState;

@property (nonatomic, strong) NSData *btFirmware;

//发送Characteristic
@property (copy, nonatomic) NSString *writeCharacteristicString;
//与设备通信Characteristic
@property (copy, nonatomic) NSString *mcuNotifyCharacteristicString;
//与蓝牙通信Characteristic
@property (copy, nonatomic) NSString *btNotifyCharacteristicString;


- (instancetype)initWithDeviceModel:(MMBluetoothDeviceModel *)model;

//------------------------------------------------------
//方法需要被子类重写

- (void)initCharacteristics;

- (void)willShakeHand:(void (^)(MMDeviceManagerOpModel *op))opBlock;

- (id)shakeHand;

- (NSData *)generateMonoDataWithImage:(UIImage *)image;
- (NSData *)generateGrayScaleDataWithImage:(UIImage *)image;

- (NSData *)packPrintData:(NSData *)data;

- (NSData *)packPrintData:(NSData *)data PrintType:(PrintPaperType)type deviceType:(NSString *)deviceType withFeedline:(BOOL)needFeedline op:(void (^)(MMDeviceManagerOpModel *op))opBlock;

- (NSArray *)disposalData:(NSData *)data;

- (void)unpackData:(NSData *)data
          complete:(void (^)(MMDeviceManagerOpModel *op))complete;

- (void)unpackBTData:(NSData *)data
            complete:(void (^)(MMDeviceManagerOpModel *op))complete;

- (void)registComplete:(void (^)(MMDeviceManagerOpModel *op))complete;

- (void)didFinishSendData:(void (^)(MMDeviceManagerOpModel *op))complete;

- (void)setBTFirmware:(NSData *)BTFirmware withOperation:(void (^)(MMDeviceManagerOpModel *op))operation;

- (void)setFirmware:(NSData *)firmware withOperation:(void (^)(MMDeviceManagerOpModel *op))operation;

//new
@property (nonatomic,strong) CBCharacteristic *writeC;
@property (nonatomic,strong) CBCharacteristic *mcuNotifyC;
@property (nonatomic,strong) CBCharacteristic *btNotifyC;

@property (nonatomic,strong) MMThermalDeviceHandle *thermalHandle;

/// 切换至新协议
- (void)convertToThermalHandle;

//new end
@end

NS_ASSUME_NONNULL_END
