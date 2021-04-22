//
//  MMBluetoothDeviceModel.h
//  Paperang
//
//  Created by hoho on 2016/11/17.
//  Copyright © 2016年 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "DBModelDeviceHistory.h"
#import "MMBLEDefines.h"

typedef NS_ENUM(uint8_t, BLEPrintDensity) {
    BLEPrintDensityDefault = 75,
    BLEPrintDensityLight = 55,
    BLEPrintDensityConcentrated = 95,
};

@class MMCloudWifiModel;

@interface MMBluetoothDeviceModel : NSObject

@property (copy, nonatomic) NSString *deviceName;

@property (copy, nonatomic) NSString *deviceType;

@property (copy, nonatomic) NSString *countryName;

@property (copy, nonatomic) NSString *guid;

@property (copy, nonatomic) NSString *alias;

@property (copy, nonatomic) NSString *identifier;

@property (copy, nonatomic) NSString *snCode;

@property (copy, nonatomic) NSString *factoryStatus;

@property (copy, nonatomic) NSString *date;

@property (copy, nonatomic) NSString *MAC;

@property (copy, nonatomic) NSString *btModel;

@property (copy, nonatomic) NSString *UUID;

@property (copy, nonatomic) NSString *firmVersion;

@property (copy, nonatomic) NSString *btVersion;

@property (copy, nonatomic) NSString *btFirmVersionNew;

@property (copy, nonatomic) NSString *btFirmDownloadPath;

@property (copy, nonatomic) NSString *firmVersionNew;

@property (copy, nonatomic) NSString *firmVersionMD5;

@property (copy, nonatomic) NSString *btFirmVersionMD5;

@property (nonatomic,copy) NSString *firmVersionNewName;
@property (nonatomic,copy) NSData *currentFirmVersionNameData;

@property (copy, nonatomic) NSString *firmDownloadPath;

@property (copy, nonatomic) NSString *updateDescription;

@property (assign, nonatomic) uint8_t battery;

@property (assign, nonatomic) uint8_t density;

@property (assign, nonatomic) uint16_t offTime;

@property (strong, nonatomic) CBPeripheral *peripheral;

@property (assign, nonatomic) NSInteger RSSI;

@property (strong, nonatomic) NSString *paperInfo;

@property (assign, nonatomic) NSInteger dbMainKey;

//new
@property (nonatomic,copy) NSString *ram;
@property (nonatomic,copy) NSString *rom;
@property (nonatomic,assign) BOOL hasWifi;
@property (nonatomic,assign) BOOL hasEthernet;
@property (nonatomic,copy) NSString *bindInfo;
//@property (nonatomic,strong) NSArray<MMCloudWifiModel*> *wifiModels;
@property (nonatomic,copy) NSString *delegateVersion;
@property (nonatomic,assign) double vol;
@property (nonatomic,assign) double temp;

//

- (void)setDataWithDBModel:(DBModelDeviceHistory *)dbmd;

- (NSString *)getVersionStringFromVersionData;

/// 当前属于系列(p1,p2,p3,d1,c,bang)
- (MMDeviceSerial)currentSerial;

/// 当前设备类型(p1,p1L,p1S,p2,p2S,.....)
- (MMDeviceSubType)currentSubType;

//- (instancetype)initWithDBModel:(DBModelDeviceHistory *)dbmd;
//- (instancetype)initWithPara:(NSDictionary *)para;

@end

