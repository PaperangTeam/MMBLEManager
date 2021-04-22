//
//  MMDeviceProtocolDefine.h
//  Paperang
//
//  Created by hoho on 2019/7/9.
//  Copyright © 2019 Hoho. All rights reserved.
//

#ifndef MMDeviceProtocolDefine_h
#define MMDeviceProtocolDefine_h
#import <Foundation/Foundation.h>
#import "MM_PRT_DEFINE.h"
#import "MMAlarmInfoModel.h"

@class MMDeviceManagerOpModel;


typedef NS_ENUM(NSInteger, PrintPaperType) {
    PrintPaperTypeNormal,
    PrintPaperTypeLabel
};

typedef NS_ENUM(uint8_t, PaperMode) {
    PaperModeNormal = 0x00,
    PaperModeLabel = 0x01
};

@protocol PaperangBaseProtocol <NSObject>

@property (assign, nonatomic) NSInteger printWidth;

@property (assign, nonatomic) NSInteger imageWidth;

//发送Characteristic
@property (copy, nonatomic) NSString *writeCharacteristicString;
//与设备通信Characteristic
@property (copy, nonatomic) NSString *mcuNotifyCharacteristicString;
//与蓝牙通信Characteristic
@property (copy, nonatomic) NSString *btNotifyCharacteristicString;

- (void)initCharacteristics;

- (id)shakeHand;

- (NSData *)packPrintData:(NSData *)data;

- (NSData *)packPrintData:(NSData *)data
                PrintType:(PrintPaperType)type
               deviceType:(NSString *)deviceType
             withFeedline:(BOOL)needFeedline
                       op:(void (^)(MMDeviceManagerOpModel *op))opBlock;

- (void)unpackData:(NSData *)data
          complete:(void (^)(MMDeviceManagerOpModel *op))complete;
- (void)unpackBTData:(NSData *)data
            complete:(void (^)(MMDeviceManagerOpModel *op))complete;

- (NSArray *)disposalData:(NSData *)data;


@end

@protocol PaperangPRTProtocol <NSObject, PaperangBaseProtocol>

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

- (NSArray *)getNormalDataWithType:(uint8_t)type
                             value:(uint8_t *)value
                            length:(uint16_t)length
                               key:(uint32_t)key;
//unpack data

- (void)unpackBTData:(NSData *)data
            complete:(void (^)(MMDeviceManagerOpModel *op))complete;
//update BK BT
- (NSArray *)startBTOTAMode;
- (NSArray *)eraseBTFlashWithData:(NSData *)data;
- (BOOL)verifyBTUpdateData:(NSData *)data;
- (NSArray *)unpackBTUpdateData:(NSData *)data;
- (NSArray *)operateBTUpdateData:(NSData *)data;


@end

@protocol PaperangPSerialProtocol <NSObject, PaperangPRTProtocol>



@end

// !!!:P2S协议
@protocol PaperangP2SProtocol <NSObject, PaperangPSerialProtocol>

@property (nonatomic,assign) NSInteger todayTomatoCount;

/**
 设置时间
 */
- (NSArray <NSData*> *)setTimeWithYear:(NSUInteger)year
                  month:(NSUInteger)month
                    day:(NSUInteger)day
                   hour:(NSUInteger)hour
                 minute:(NSUInteger)minute
                 second:(NSUInteger)second;

/**
 设置小时制
 */
- (NSArray <NSData*> *)setTimeModeWithIs24Hour:(BOOL)is24Hour;


/**
 获得小时制
 */
- (NSArray <NSData*> *)getTimeMode;

/**
 设置番茄时钟提醒纸条开关
 */
- (NSArray <NSData*> *)setTomatoNoteOn:(BOOL)isOn;

/**
 获得番茄时钟提醒纸条开关状态
 */
- (NSArray <NSData*> *)getTomatoNoteOn;

/**
 设置番茄时钟提醒纸条数据
 */
- (NSArray <NSData*> *)setTomatoNoteDataWithImage:(UIImage *)image;

/**
 设置闹钟提醒纸条开关
 */
- (NSArray <NSData*> *)setAlarmNoteOn:(BOOL)isOn;

/**
 获得闹钟提醒纸条开关
 */
- (NSArray <NSData*> *)getAlarmNoteOn;

/**
 设置闹钟提醒纸条数据
 */
- (NSArray <NSData*> *)setAlarmNoteWithImage:(UIImage *)image;

/// 纸条预先包
- (NSArray <NSData*> *)getSetNotePreActionDatas;

/**
 设置按键音
 */
- (NSArray <NSData*> *)setKeySoundOn:(bool)isOn;

/**
 获得按键音
 */
- (NSArray <NSData*> *)getKeySoundOn;

/**
 设置计时提示音
 */
- (NSArray <NSData*> *)setTimerSoundIsOn:(BOOL)isOn;

/**
 获得计时提示音开关
 */
- (NSArray <NSData*> *)getTimerSoundOn;

/**
 设置闹钟提示音
 */
- (NSArray <NSData*> *)setAlarmSoundOn:(BOOL)isOn;

/**
 获得闹钟提示音状态
 */
- (NSArray <NSData*> *)getAlarmSoundOn;

/**
 设置闹钟延时提醒开关
 */
- (NSArray <NSData*> *)setAlarmDelayOn:(BOOL)isOn;

/**
 获得闹钟延时提醒开关状态
 */
- (NSArray <NSData*> *)getAlarmDelayOn;

/**
 设置闹钟延时提醒时间,单位为分钟
 */
- (NSArray <NSData*> *)setAlarmDelayTimeWithMinutes:(NSInteger)minutes;

/**
 获得闹钟延时提醒时间
 */
- (NSArray <NSData*> *)getAlarmDelayTime;

/**
 设置番茄时钟提示音
 */
- (NSArray <NSData*> *)setTomatoSoundIsOpen:(BOOL)isOpen;

/**
 获得番茄时钟提示音
 */
- (NSArray <NSData*> *)getTomatoSoundStatus;

/**
 设置熄屏时间,单位为秒
 */
- (NSArray <NSData*> *)setSuspendTimeSecond:(NSInteger)second;

/**
 获得熄屏时间,单位为秒
 */
- (NSArray <NSData*> *)getSuspendTime;

/**
 设置番茄时钟工作时间,单位为分钟
 */
- (NSArray <NSData*> *)setTomatoWorkTimeMinutes:(NSInteger)minutes;

/**
 获得番茄时钟工作时间,单位为分钟
 */
- (NSArray <NSData*> *)getTomatoWorkTime;

/**
 设置番茄时钟休息时间,单位为分钟
 */
- (NSArray <NSData*> *)setTomatoBreakTimeMinutes:(NSInteger)minutes;

/**
 获得番茄时钟休息时间,单位为分钟
 */
- (NSArray <NSData*> *)getTomatoBreakTime;

/**
 新增闹钟时间
 */
- (NSArray <NSData*> *)addAlarmTimeHour:(int)hour
                                 minute:(int)minute
                                  cycle:(uint8_t)cycle
                                 isOpen:(BOOL)isOpen
                               bellType:(int)bellType
                                isDelay:(BOOL)isDelay
                                   name:(NSString *)name
                           openAndOrder:(uint8_t)openAndOrder;

/// 删除闹钟
/// @param model model description
- (NSArray <NSData*> *)deleteAlarm:(MMAlarmInfoModel *)model;

/// 更新闹钟
/// @param model model description
- (NSArray <NSData*> *)updateAlarm:(MMAlarmInfoModel *)model;

/// 获得关机闹钟开关
- (NSArray <NSData *> *)getPowerOffAlarm;

/// 设置关机闹钟开关
/// @param isOpen 是否打开
- (NSArray <NSData *> *)setPowerOffAlarm:(BOOL)isOpen;

/**
 设置屏幕闪烁开关
 */
- (NSArray <NSData*> *)setScreenFlashIsOpen:(BOOL)isOpen;

/**
 获得屏幕闪烁开关状态
 */
- (NSArray <NSData*> *)getScreenFlashStatus;

/**
 获取番茄钟计数数据
 */
- (NSArray <NSData*> *)getTomatoCount;

/**
 获取闹钟数据
 */
- (NSArray <NSData*> *)getAlarmTime;

/**
 获得番茄钟铃声
 */
- (NSArray <NSData*> *)getTomatoSoundType;

/**
 获得计时铃声
 */
- (NSArray <NSData*> *)getCountDownSoundType;

/**
 设置番茄钟铃声
 */
- (NSArray <NSData*> *)setTomatoSoundType:(uint8_t)newType;
/**
 设置计时铃声
 */
- (NSArray <NSData*> *)setCountDownSoundType:(uint8_t)newType;

/**
 播放铃声
 */
- (NSArray <NSData*> *)playSoundWithType:(int)type;

/**
 停止播放铃声
 */
- (NSArray <NSData*> *)stopPlaySound;



@end

@protocol PaperangCSerialProtocol <NSObject, PaperangPRTProtocol>



@end

@protocol PaperangTSerialProtocol <NSObject, PaperangPRTProtocol>

@property (assign, nonatomic) BOOL showCutMark;

@end

@protocol PaperangGTSerialProtocol <NSObject, PaperangBaseProtocol>

@property (strong, nonatomic) NSDictionary *rollStatus;

@end

typedef NS_ENUM(NSInteger, BangDensity) {
    BangDensityLight = 0,
    BangDensityNormal,
    BangDensityStrong,
};

@protocol PaperangIBangProtocol <NSObject, PaperangBaseProtocol>

@property (assign, nonatomic) NSInteger MTU;

@property (assign, nonatomic) NSInteger credit;

- (void)unpackBTData:(NSData *)data
            complete:(void (^)(MMDeviceManagerOpModel *op))complete;
@end

#endif /* MMDeviceProtocolDefine_h */
