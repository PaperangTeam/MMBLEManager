//
//  MMBLENormalManager.h
//  MMBLENormalManager
//
//  Created by 王明阳 on 2019/8/17.
//  Copyright © 2019 qq_29429535. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMBLEDefines.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import "MMDeviceDelegate.h"

@class MMCloudDelegate;
@class MMShareListModel;
//@class MMDeviceUsingManager;
//@class MMUsingDevice;

typedef void(^GetMacBlock)(NSString *mac);

extern NSNotificationName const BLEManagerDidDiscoverPeripheralNotification;
extern NSNotificationName const BLEManagerWillConnectPeripheralNotification;
extern NSNotificationName const BLEManagerDidConnectPeripheralNotification;
extern NSNotificationName const BLEManagerDidFailToConnectPeripheralNotification;
extern NSNotificationName const BLEManagerDidDisconnectPeripheralNotification;
extern NSNotificationName const BLEManagerDidReciveDataNotification;
extern NSNotificationName const BLEManagerDidFinishSendDataNotification;
extern NSNotificationName const BLEManagerDidWillSendDataNotification;
extern NSNotificationName const BLEManagerDidUpdateSuccessNotification;
extern NSNotificationName const BLEManagerDidUpdateDensity;
extern NSNotificationName const BLEManagerFailUpdateDensity;
extern NSNotificationName const BLEManagerDidUpdateOfftime;
extern NSNotificationName const BLEManagerFailUpdateOfftime;
extern NSNotificationName const BLEManagerUpdatePackageNotification;
//p2s
extern NSNotificationName const BLEManagerDidGetTimeModeNotification;
extern NSNotificationName const BLEManagerDidGetTomatoNoteStatusNotification;
extern NSNotificationName const BLEManagerDidGetAlarmNoteStatusNotification;
extern NSNotificationName const BLEManagerDidGetKeySoundStatusNotification;
extern NSNotificationName const BLEManagerDidGetTimerSoundStatusNotification;
extern NSNotificationName const BLEManagerDidGetAlarmSoundStatusNotification;
extern NSNotificationName const BLEManagerDidGetAlarmDelayStatusNotification;
extern NSNotificationName const BLEManagerDidGetAlarmDelayTimeNotification;
extern NSNotificationName const BLEManagerDidGetTomatoSoundStatusNotification;
extern NSNotificationName const BLEManagerDidGetSuspendTimeNotification;
extern NSNotificationName const BLEManagerDidGetTomatoWorkTimeNotification;
extern NSNotificationName const BLEManagerDidGetTomatoBreakTimeNotification;
extern NSNotificationName const BLEManagerDidGetScreenFlashStatusNotification;
extern NSNotificationName const BLEManagerDidGetTomatoCountNotification;
extern NSNotificationName const BLEManagerDidGetAlarmDataNotification;

extern NSNotificationName const BLEManagerDidSetTimeModeNotification;
extern NSNotificationName const BLEManagerDidSetTomatoNoteStatusNotification;
extern NSNotificationName const BLEManagerDidSetAlarmNoteStatusNotification;
extern NSNotificationName const BLEManagerDidSetKeySoundStatusNotification ;
extern NSNotificationName const BLEManagerDidSetTimerSoundStatusNotification;
extern NSNotificationName const BLEManagerDidSetAlarmSoundStatusNotification;
extern NSNotificationName const BLEManagerDidSetAlarmDelayStatusNotification;
extern NSNotificationName const BLEManagerDidSetAlarmDelayTimeNotification;
extern NSNotificationName const BLEManagerDidSetTomatoSoundStatusNotification;
extern NSNotificationName const BLEManagerDidSetSuspendTimeNotification;
extern NSNotificationName const BLEManagerDidSetTomatoWorkTimeNotification;
extern NSNotificationName const BLEManagerDidSetTomatoBreakTimeNotification;
extern NSNotificationName const BLEManagerDidSetScreenFlashStatusNotification;
extern NSNotificationName const BLEManagerDidSetAlarmTimeNotification;
extern NSNotificationName const BLEManagerDidSetAlarmTimeFaildNotification;

extern NSNotificationName const BLEManagerDidSetTomatoNoteSuccessNotification ;
extern NSNotificationName const BLEManagerDidSetTomatoNoteFailedNotification ;
extern NSNotificationName const BLEManagerDidSetAlarmNoteSuccessNotification ;
extern NSNotificationName const BLEManagerDidSetAlarmNoteFailedNotification ;

extern NSNotificationName const BLEManagerDidGetTomatoSoundTypeNotification;
extern NSNotificationName const BLEManagerDidGetCountDownSoundTypeNotification;
extern NSNotificationName const BLEManagerDidGetPowerOffAlarmNotification;
//激活设备相关@{@"sn":xxxx,@"model":xxx}
//extern NSNotificationName const BLEManagerStartActivatingDeviceNotification;//开始进行激活
extern NSNotificationName const BLEManagerActivatingDeviceNetworkFaildNotification;//激活时网络故障
extern NSNotificationName const BLEManagerActivatingDeviceLockedNotification;//该设备已被锁
extern NSNotificationName const BLEManagerActivatingDeviceSuccessNotification;//激活成功
extern NSNotificationName const BLEManagerActivatingStartRequestNetNotification;//开始进行网络激活
extern NSNotificationName const BLEManagerActivatingStartCheckNotification;//开始检查
extern NSNotificationName const BLEManagerDeviceConnectFailNotification;//设备连接失败
extern NSNotificationName const BLEManagerDeviceConnectSuccessNotification;//设备连接成功

extern NSNotificationName const MMTimerTomatoesChangeFinishNotification;


extern NSNotificationName const MMDidFinishPrintNotification;
extern NSNotificationName const MMSendDataProgressNotification;
extern NSNotificationName const MMDeviceExceptionStatusNotification;
extern NSNotificationName const MMDisconnectBTCMDNotification;


NS_ASSUME_NONNULL_BEGIN

//API_AVAILABLE(ios(10.0))
@interface MMBLENormalManager : NSObject

@property (assign, nonatomic) uint8_t strong;
@property (assign) uint8_t normal;
@property (assign) uint8_t light;
@property (assign) BOOL isUserConnect;
@property (assign) BOOL isUserDisConnect;
@property (strong, nonatomic) MMDeviceDelegate *connectedDevice;
@property (nonatomic, assign) NSTimeInterval scanTime;
@property (nonatomic, assign) BOOL autoReconnect;

/// 重新连接使用
@property (nonatomic,strong) MMDeviceDelegate *tryConnectDevice;

/**
 最近一次连接的设备type
 */
@property (nonatomic, strong, readonly) NSString *lastConnectDeviceType;

@property (assign) PaperMode mode;

@property (assign, nonatomic) NSInteger printCount;

@property (nonatomic, copy) NSString *needConnectId;

@property (nonatomic, copy) NSString *needConnectMAC;

/**
 蓝牙搜索设备类型
 */
@property (nonatomic,assign)BLESearchDeviceType searchType;

@property (nonatomic, assign) UpdateType updateType;
// !!!:注意版本
@property (assign, nonatomic) CBManagerState state;

@property (nonatomic, assign) NSInteger retryCount;                  //for read print model
@property (nonatomic, assign) BOOL isExceptionPrintModel;               //判断是否设备类型读取异常
@property (nonatomic, assign) BOOL ignoreLowPower;
@property (nonatomic, assign) BOOL ignoreFeedToHead;
@property (nonatomic, assign) BOOL isCreditInit;
@property (nonatomic, assign) BOOL needUpload;
@property (nonatomic, assign) BOOL isShowCutMark;
@property (nonatomic, copy) void(^batteryComplete)(uint8_t batteryStatus);
@property (nonatomic, copy) void(^printNum)(uint32_t printNum);
@property (nonatomic, assign) BOOL isUpdateRestart;
@property (nonatomic, strong) CBPeripheral *updatePeripheral;
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSTimer *connectTimer;

@property (nonatomic, assign) NSInteger isA5Protocol;
/**
 获得单例

 @return return value description
 */
+ (instancetype)manager NS_SWIFT_NAME(shared());

/**
 发送数据

 @param array 数组
 */
- (BOOL)writeDataWithArray:(NSArray *)array;
- (BOOL)isCanSendData;

- (void)scanPeripheral;
- (void)stopScan;
- (void)refresh;

/// 断开设备
/// @param identifier identifier description
- (void)disconnect;
- (void)disconnectWithIdentifier:(NSString *)identifier;
- (void)disconnectMiaomiaoji;
- (void)reconnect;
- (void)feedToHeadLine;
- (void)searchOurAccessory;

/// 连接设备
/// @param identify 标识符
/// @param isTimeLimit 是否限制时间
- (void)connectPeripheralWithIdentify:(NSString *)identify isTimeLimit:(BOOL)isTimeLimit;
- (void)connectPeripheralWithMAC:(NSString *)mac;
- (void)connectPeripheral:(CBPeripheral *)peripheral;
- (void)cancelPeripheralConnection:(CBPeripheral *)peripheral;

//普通打印
- (BOOL)printImage:(UIImage *)image;
- (BOOL)printImage:(UIImage *)image
      withFeedline:(BOOL)needFeedline;
- (BOOL)printImage:(UIImage *)image type:(PrintPaperType)type;

//灰阶打印
- (BOOL)printGrayScaleImage:(UIImage *)image;
- (BOOL)printGrayScaleImage:(UIImage *)image
               withFeedline:(BOOL)needFeedline;
- (BOOL)printGrayScaleImage:(UIImage *)image
                       type:(PrintPaperType)type;
- (BOOL)printGrayScaleImage:(UIImage *)image
                       type:(PrintPaperType)type
               withFeedline:(BOOL)needFeedline;

/// 单色图打印(无灰阶)
- (BOOL)printMonoImage:(UIImage *)image;
- (BOOL)printMonoImage:(UIImage *)image withFeedline:(BOOL)needFeedline;
/// 纯文本打印
- (BOOL)printMonoImage:(UIImage *)image type:(PrintPaperType)type;


- (BOOL)test:(NSData *)data;
- (BOOL)test:(NSData *)data deviceType:(NSString *)type;
- (BOOL)test:(NSData *)data type:(PrintPaperType)type;
- (BOOL)test:(NSData *)data
        type:(PrintPaperType)type
  deviceType:(NSString *)deviceType
withFeedline:(BOOL)needFeedline;

- (void)printData:(NSData *)data withLabelAndSetGap:(uint8_t)gapLength;
- (void)updateFirmware:(NSData *)data;
/// 更新固件
- (BOOL)isRightFirmware:(NSData *)firmware;
- (BOOL)isRightBTFirmware:(NSData *)btFirmware;
- (void)setFirmware:(NSData *)firmware;
- (void)setBTFirmware:(NSData *)BTFirmware;
- (void)setDeviceDensity:(uint8_t)density;
- (void)setFactoryStatus:(uint8_t)factoryStatus;
- (void)setAutoOffTime:(uint16_t)time;

/// 获取关机时间
- (void)getOffTime;

- (void)setPaperMode:(uint8_t)mode;
- (void)setBluetoothOTAModel;
- (void)getBatteryStatusComplete:(void(^)(uint8_t batteryStatus))complete;
- (void)getPrintNum:(void(^)(uint32_t printNum))complete;

- (void)printOrigin64Image:(UIImage *)image;
- (void)printPure64Image:(UIImage *)image;
- (void)printTestPage;
- (CGFloat)calculateMMJPrintLength:(UIImage * )image;

/// 判断是非已经连接蓝牙耳机
- (BOOL)isBluetoothHeadsetConnected;

/// 判断是否连接上了设备
- (BOOL)jungleConnectDeviceAction;

//打印剪切标记
- (void)showCutMark:(BOOL)cutMark;

//test
- (void)testCommand;

// Upgrade
- (BOOL)needUpdate;
- (void)showHelperView;

//- (BOOL)printImage:(UIImage *)image
//              type:(PrintPaperType)type
//        deviceType:(NSString *)deviceType
//        withPoints:(NSArray *)points
//      withFeedline:(BOOL)needFeedline;

- (BOOL)printImage:(UIImage *)image
              type:(PrintPaperType)type
        withPoints:(NSArray *)points
      withFeedline:(BOOL)needFeedline;

// !!!:代码块

- (void)registDeviceSuccess:(void (^)(void))success
                     Failue:(void (^)(int code,NSString *result))fail
          networkFaildBlock:(void (^)(void))networkFaildBlock;


/// 上报升级记录
/// @param isSuccess isSuccess description
/// @param completion completion description
- (void)updateResultRecordWithIsSuccess:(BOOL)isSuccess
                             completion:(void (^)(bool isSuccess))completion;

/**
 是否禁止头部走纸
 */
@property (nonatomic,assign) BOOL disPrintTopFeed;

/// 连接上一次的设备，如果没有，则返回nil
- (DBModelDeviceHistory *)connectLastDevice;

//new start

/// 历史所有设备，仅喵喵机
- (NSArray<DBModelDeviceHistory*> *)historyDevices;

- (CBCentralManager *)currentCentral;

/// 打印图片,新增
/// @param image 图片
/// @param count 份数
- (BOOL)mmPrintImage:(UIImage *)image count:(NSInteger)count;

/// 检查是否可打印
/// @param isHandle 是否处理未连接
- (BOOL)checkCanPrintImageWithIsHandle: (BOOL)isHandle;

/// 断开所有设备蓝牙连接/云连接
- (void)disconnectAllDevice;

/// 删除历史设备,喵喵机
/// @param identifier identifier description
- (void)deleteMMHistoryWithIdentifier:(NSString *)identifier;


- (BOOL)isNewUpdate;

/// 升级新协议设备
- (void)beginUpdate;

- (void)checkUpdate;

//new end

@end

NS_ASSUME_NONNULL_END
