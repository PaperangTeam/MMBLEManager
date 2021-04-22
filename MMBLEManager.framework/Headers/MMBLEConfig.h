//
//  MMBLEConfig.h
//  Pods
//
//  Created by 王明阳 on 2019/8/24.
//

#import <Foundation/Foundation.h>
#import "MMDeviceInfoManager.h"

typedef void(^registDeviceResultBlock)(BOOL isSuccess,int code,NSString *result,BOOL isInActivating);

@class MMUsingDevice;

NS_ASSUME_NONNULL_BEGIN

@interface MMBLEConfig : NSObject

/// 是否使用go接口，国际版用go
//@property (nonatomic,assign) BOOL useGoApi;

@property (nonatomic,assign) BOOL ignoreP2S;

@property (nonatomic,assign) BOOL isDebug;

@property (nonatomic,assign) BOOL hadCrcKey;

/**
 根据设备类型获得名称
 */
@property (nonatomic,copy) NSString *(^getDeviceNameBlock)(MMDeviceType type);

+ (instancetype)share;

// !!!:代码块

@property (nonatomic,copy) NSString *(^getCurrentUserIdBlock)(void);

@property (nonatomic,copy) void (^helperViewSetStatuBlock)(uint16_t status);

//PRT_SEND_PRINTED_LINE_NUM
@property (nonatomic,copy) void (^handleSendPrintLineNumBlock)(NSArray *values);

//PRT_SEND_PRINTED_LABEL_NUM
@property (nonatomic,copy) void (^handleSendPrintedLabelNumBlock)(NSArray *values);

@property (nonatomic,copy) void (^handleDisconnectBTCmdBlock)(void);

/**
 执行registDevice之前
 */
@property (nonatomic,copy) void (^beforeRegistDeviceBlock)(registDeviceResultBlock resultBlock);

@property (nonatomic,copy) void (^handleRegistDeviceSuccessShowHudBlock)(void);

/**
 注册成功后，处理纸张
 */
@property (nonatomic,copy) void (^handlePaperAfterRegistDeviceBlock)(void);

/**
 蓝牙关闭后
 */
@property (nonatomic,copy) void (^handleBLEPoweredOffBlock)(MMUsingDevice *lastUseDevice,
NSString *mmIdentifier);

/**
 过滤设备名
 */
//@property (nonatomic,strong) NSArray *discoverDeviceIgnoreArray;

/**
 允许设备名
 */
@property (nonatomic,strong) NSArray *discoverNameArray;

/**
 不允许搜索的名字，优先级最高
 */
@property (nonatomic,strong) NSArray *unEnableNameArray;

@property (nonatomic,assign) BOOL isCN;

@property (nonatomic,copy) void (^handleDidDisconnectPeripheral)(void);

@property (nonatomic,copy) void (^handlePrintImageButNotConnectBlock)(BOOL hasHistory);

@property (nonatomic,copy) void (^handlePrintImageSuccessBlock)(void);

@property (nonatomic,copy) void (^didFinishtSendDataBlock)(void);

@property (nonatomic,copy) BOOL (^shouldUpdateBlock)(void);

@property (nonatomic,copy) void (^didUpdateSuccessBlock)(void);

@property (nonatomic,copy) NSDictionary *(^registDeviceParaBlock)(void);

//@property (nonatomic,copy) NSData *(^lzo_compressDataBlock)(NSData *data);

@property (nonatomic,copy,nullable) void (^useChangeBlock)(MMUsingDevice *useDevice);

@property (nonatomic,assign) BOOL isAllowUpgradeWhenEqual;

@end

NS_ASSUME_NONNULL_END
