//
//  MMBLEDefines.h
//  MMBLEManager
//
//  Created by 王明阳 on 2019/8/17.
//  Copyright © 2019 qq_29429535. All rights reserved.
//

#ifndef MMBLEDefines_h
#define MMBLEDefines_h

#define CONNECT_DEVICE_MAX_SECOND 30 //连接设备最长时间等待

#define DEVICE_NAME @"MiaoMiaoJi"
#define DEVICE_INTERNATIONAL_NAME @"Paperang"
#define DEVICE_DENSITY 65
#define kIbridgeProtocolString @"com.brt.com.ibridge"
#define tempRootPath [NSString stringWithFormat:@"%@/MMTempData",NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject]
#define SCREEN_BOUNDS [UIScreen mainScreen].bounds
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

#ifndef WEAKSELF
#define WEAKSELF __weak typeof(self)weakself = self;
#endif

/**
 禁止使用init方法
 */
#ifndef UN_AVAILABLE_INIT
#define UN_AVAILABLE_INIT -(instancetype) init NS_UNAVAILABLE
#endif

/**
 禁止使用new方法
 */
#ifndef UN_AVAILABLE_NEW
#define UN_AVAILABLE_NEW +(instancetype) new NS_UNAVAILABLE
#endif

/**
 禁止使用init、new方法
 */
#ifndef UN_AVAILABLE_SYSTEM_INIT
#define UN_AVAILABLE_SYSTEM_INIT UN_AVAILABLE_INIT;\
UN_AVAILABLE_NEW;
#endif


// !!!:蓝牙搜索的设备类型
typedef NS_ENUM(NSInteger,BLESearchDeviceType) {
    BLESearchDeviceTypeAll = 1,//全部类型
    BLESearchDeviceTypeMiaomiaoji = 1<<1,//喵喵机
    BLESearchDeviceTypeTiaotiaoji = 1<<2,//条条机
};

typedef NS_ENUM(NSInteger, UpdateType) {
    UpdateTypeNone,
    UpdateTypeFirm,             //升级固件
    UpdateTypeBluetooth         //升级蓝牙
};

typedef NS_ENUM(NSInteger, BLEWriteDataType) {
    BLEWriteDataImage = 0,
    BLEWriteDataUpdateFirmware
};

/// 设备系列
typedef NS_ENUM(NSInteger, MMDeviceSerial) {
    MMP1Serial = 1,
    MMP2Serial,
    MMP3Serial,
    MMDSerial,
    MMTSerial,
    MMCSerial,
    MMBangSerial,  ///< 帮帮机
    MMXSerial,   ///< 小盒子
};

/// 设备类型(按出厂名设置)
typedef NS_ENUM(NSInteger, MMDeviceSubType) {
    //-------------------P1
    MMPSerialSubTypeP1 = 1,
    MMPSerialSubTypeP1L,
    MMPSerialSubTypeP1S,
    //-------------------P2
    MMPSerialSubTypeP2,
    MMPSerialSubTypeP2S,
    //-------------------P3
    MMPSerialSubTypeP3,
    //-------------------D1
    MMPSerialSubTypeD1,
    //-------------------T1
    MMTSerialSubTypeT1,
    //-------------------C1
    MMCSerialSubTypeC1,
    //-------------------iBang
    MMGTSerialSubTypeIBang,
    //-------------------X2
    MMXSerialSubTypeX2,
};

static NSString *const kDeviceType_T1 = @"T1";
static NSString *const kDeviceType_P1L = @"P1L";
static NSString *const kDeviceType_P2 = @"P2";
static NSString *const kDeviceType_D1 = @"D1";
static NSString *const kDeviceType_C1 = @"C1";
static NSString *const kDeviceType_P2S = @"P2S";
static NSString *const kDeviceType_P1S = @"P1S";
static NSString *const kDeviceType_BS1 = @"BS1";
static NSString *const kDeviceType_P3 = @"P3";
static NSString *const kDeviceType_X2 = @"X2";

static inline NSDictionary<NSString *, NSNumber *> *deviceTypesDataSource() {
    return @{
        kDeviceType_T1 : @(MMTSerialSubTypeT1),
        kDeviceType_P1L : @(MMPSerialSubTypeP1L),
        kDeviceType_P1S : @(MMPSerialSubTypeP1S),
        kDeviceType_P2 : @(MMPSerialSubTypeP2),
        kDeviceType_P2S : @(MMPSerialSubTypeP2S),
        kDeviceType_P3 : @(MMPSerialSubTypeP3),
        kDeviceType_C1 : @(MMCSerialSubTypeC1),
        kDeviceType_D1 : @(MMPSerialSubTypeD1),
        kDeviceType_BS1 : @(MMGTSerialSubTypeIBang),
        kDeviceType_X2 : @(MMXSerialSubTypeX2),
    };
}

static inline MMDeviceSubType deviceSubTypeWithDeviceType(NSString *deviceType) {
    if (!deviceType || deviceType.length == 0) {
        return MMPSerialSubTypeP1;
    }
    
    MMDeviceSubType subType = MMPSerialSubTypeP1;
    BOOL isContain = [deviceTypesDataSource().allKeys containsObject:deviceType];
    if (!isContain) {
        return subType;
    }
    
    subType = (MMDeviceSubType)[deviceTypesDataSource()[deviceType] intValue];
    return subType;
}

static inline MMDeviceSerial serialWithDeviceType(NSString *deviceType) {
    MMDeviceSubType subType = deviceSubTypeWithDeviceType(deviceType);
    MMDeviceSerial serial = MMP1Serial;
    switch (subType) {
        case MMPSerialSubTypeP1:
        case MMPSerialSubTypeP1L:
        case MMPSerialSubTypeP1S:
            serial = MMP1Serial;
            break;
        case MMPSerialSubTypeP2:
        case MMPSerialSubTypeP2S:
            serial = MMP2Serial;
            break;
        case MMPSerialSubTypeP3:
            serial = MMP3Serial;
            break;
        case MMPSerialSubTypeD1:
            serial = MMDSerial;
            break;
        case MMTSerialSubTypeT1:
            serial = MMTSerial;
            break;
        case MMCSerialSubTypeC1:
            serial = MMCSerial;
            break;
        case MMGTSerialSubTypeIBang:
            serial = MMBangSerial;
            break;
        case MMXSerialSubTypeX2:
            serial = MMXSerial;
        default:
            break;
    }
    
    return serial;
}

static inline CGFloat deviceTypeImageWidth(MMDeviceSubType subType) {
    CGFloat imageWidth = 384;
    switch (subType) {
        case MMPSerialSubTypeP1:
        case MMPSerialSubTypeP1L:
        case MMPSerialSubTypeP1S:
            imageWidth = 384;
            break;
        case MMPSerialSubTypeP2:
        case MMPSerialSubTypeP2S:
            imageWidth = 576;
            break;
        case MMPSerialSubTypeP3:
            imageWidth = 864;
            break;
        case MMPSerialSubTypeD1:
            imageWidth = 384;
            break;
        case MMTSerialSubTypeT1:
            imageWidth = 96;
            break;
        case MMCSerialSubTypeC1:
            imageWidth = 1248;
            break;
        case MMGTSerialSubTypeIBang:
            imageWidth = 864;
            break;
        case MMXSerialSubTypeX2:
            imageWidth = 2100;
            break;
        default:
            break;
    }
    
    return imageWidth;
}

#endif /* MMBLEDefines_h */
