//
//  PRT_DEFINE.h
//  Paperang
//
//  Created by hoho on 2016/12/20.
//  Copyright © 2016年 Hoho. All rights reserved.
//

#ifndef MM_PRT_DEFINE_h
#define MM_PRT_DEFINE_h


#define PRT_PRINT_HEAD 0x02
#define PRT_PRINT_END 0x03

#define PRT_KEY 0x35769521

#define PRT_FEED_LINE_LENGTH_P1 280 ///< p1默认走纸点行
#define PRT_FEED_LINE_LENGTH_P2 280 ///< p2默认走纸点行
#define PRT_FEED_LINE_LENGTH_C1 140 ///< C1默认走纸点行
#define PRT_FEED_LINE_LENGTH_P2S 100 ///< P2S默认走纸点行

typedef NS_ENUM(uint8_t, PRT_BLE_TYPE) {
    
    PRT_PRINT_DATA = 0, ///<正常的打印数据
    PRT_PRINT_DATA_COMPRESS ,///<压缩的打印数据1
    PRT_FIRMWARE_DATA,///<程序升级数据2
    PRT_USB_UPDATE_FIRMWARE,///<发送usb升级指令3
    PRT_GET_VERSION,///<app获取VERSION4
    PRT_SENT_VERSION,///<打印机发送版本信息5
    
    PRT_GET_MODEL,///<app获取设备型号6
    PRT_SENT_MODEL,///<打印机发送设备型号7
    
    PRT_GET_BT_MAC,///<app获取蓝牙MAC8
    PRT_SENT_BT_MAC,///<打印机发送蓝牙MAC9
    
    PRT_GET_SN,///<app获取打印机序列号a
    PRT_SENT_SN,///<打印机发送打印机序列号b
    
    
    PRT_GET_STATUS,///<app获取打印机状态c
    PRT_SENT_STATUS,///<打印机发送打印机状态d
    
    PRT_GET_VOLTAGE,///<app获取打印机电池电压e
    PRT_SENT_VOLTAGE,///<打印机发送打印机电池电压f
    
    PRT_GET_BAT_STATUS,///<app获取打印机电池电压状态10
    PRT_SENT_BAT_STATUS,///<打印机发送打印机电池电压状态11
    
    
    PRT_GET_TEMP,///<app获取打印机TPH温度12
    PRT_SENT_TEMP,///<打印机发送打印机TPH温度13
    
    PRT_SET_FACTORY_STATUS,///<app设置出厂标示14
    PRT_GET_FACTORY_STATUS,///<app获取打印机出厂标示15
    PRT_SENT_FACTORY_STATUS,///<打印机发送打印机出厂标示16
    
    PRT_SENT_BT_STATUS,///<打印机发送蓝牙状态17
    PRT_SET_CRC_KEY,///<app设置打印机crc key18
    
    PRT_SET_HEAT_DENSITY,///<app设置打印机浓度19
    
    PRT_FEED_LINE,///<走纸指令0.125mm为单位1a
    PRT_PRINT_TEST_PAGE,///<打印自检页字符1b
    
    PRT_GET_HEAT_DENSITY,///<app获取打印机浓度1C
    PRT_SENT_HEAT_DENSITY,///<打印机发送打印机浓度1d
    
    PRT_SET_POWER_DOWN_TIME,///<设置关机时间 2字节 最大65535秒
    
    PRT_GET_POWER_DOWN_TIME,///<app获取关机时间
    PRT_SENT_POWER_DOWN_TIME,///<打印机发送关机时间
    PRT_FEED_TO_HEAD_LINE,///<定位走纸最大距离x*0.125mm(2byte):  发送完这条指令将进行定位，如果超过x*0.125mm还没找到缝标将报错。
    
    PRT_PRINT_DEFAULT_PARA,///<22 参数恢复出厂设置
    
    PRT_GET_BOARD_VERSION,///<23 获取主板版本
    PRT_SENT_BOARD_VERSION,///<24 主板发送主板版本
    
    PRT_GET_HW_INFO,///<25   获取硬件信息
    PRT_SENT_HW_INFO,///<26  主板发送硬件信息
    
    PRT_SET_MAX_GAP_LENGTH,///<设置最大缝的长度1字节单位mm毫米   27
    PRT_GET_MAX_GAP_LENGTH,///<获取最大缝的长度28
    PRT_SENT_MAX_GAP_LENGTH,///<打印机发送29
    
    PRT_GET_PAPER_TYPE,  ///<1字节 0为收据纸，1为定位纸 2a
    PRT_SENT_PAPER_TYPE,
    PRT_SET_PAPER_TYPE,
    
    PRT_GET_COUNTRY_NAME,
    PRT_SENT_COUNTRY_NAME, ///<16字节字符数据
    
    PRT_DISCONNECT_BT_CMD,///<1 字节 固定为1
    
    PRT_GET_PRINTER_MODEL,///<获取打印机模式（p1s）
    PRT_SENT_PRINTER_MODEL,
    
    PRT_UPDATE_BT_FIRMWARE,///<32
    PRT_UPDATE_BT_BY_USB,///<33
    
    PRT_GET_PRINTED_LINE_NUM,///<34获取已打印长度 例：获取值为6120，    则6120/24*0.141  = 35.95mm
    PRT_SEND_PRINTED_LINE_NUM,///<35 发送已打印长度 4 字节 (8*6)单位为一mm35
    
    PRT_GET_PRINTER_IDLE_STATUS,///<36
    PRT_SEND_PRINTER_IDLE_STATUS,///<37
    
    PRT_REFRESH_LABEL_NUM,//38
    PRT_SET_PRINT_SPEED,//39
    PRT_GET_SPEED,//3a
    PRT_SENT_SPEED,//3b
    PRT_GET_PRINTED_LABEL_NUM,//3c
    PRT_SEND_PRINTED_LABEL_NUM,//3d
    PRT_SET_PAPER_LEARN,//3e
    PRT_SET_CACHE_TIME,//3f设置缓存时间
    PRT_SET_PAPER_PIECE,//40标签学习
    PRT_SET_BINARY_TREE_PARAMETERS,//设置二叉树参数41
    
    PRT_GET_BT_MODEL, //app获取打印机蓝牙设备型号0x42
    PRT_SENT_BT_MODEL,//打印机发送蓝牙设备型号0x43（新蓝牙返回BK3432旧蓝牙无返回）

    // !!!:p2s新增指令

    PRT_SET_TIME = 0x50,//设置时间50
    PRT_SET_TIME_MODE = 0x51,//设置时间制式 51    1 为24小时 0 为 12小时
    PRT_GET_TIME_MODE = 0x52,//52
    PRT_SENT_TIME_MODE,//53
    PRT_SET_TOMATO_NOTE_ON,//设置番茄时钟提醒纸条开关54  1开 0 关
    PRT_GET_TOMATO_NOTE_ON,//55
    PRT_SENT_TOMATO_NOTE_ON,//56
    PRT_SET_TOMATO_NOTE,//设置番茄时钟提醒纸条数据57
    PRT_SET_ALARM_NOTE_ON,//设置闹钟提醒纸条开关58   1开 0 关
    PRT_GET_ALARM_NOTE_ON,//59
    PRT_SENT_ALARM_NOTE_ON,//5A
    PRT_SET_ALARM_NOTE,//设置闹钟提醒纸条数据5B
    PRT_SET_KEY_SOUND,//设置按键音5C    1开 0 关
    PRT_GET_KEY_SOUND,//5D
    PRT_SENT_KEY_SOUNDE,//5E
    PRT_SET_TIMER_SOUND,//设置计时提示音5F  1开 0 关
    PRT_GET_TIMER_SOUND,//60
    PRT_SENT_TIMER_SOUNDE,//61
    PRT_SET_ALARM_SOUND,//设置闹钟提示音62  1开 0 关
    PRT_GET_ALARM_SOUND,//63
    PRT_SENT_ALARM_SOUNDE,//64
    PRT_SET_ALARM_DELAY,//设置闹钟延时提醒开关65  1开 0 关
    PRT_GET_ALARM_DELAY,//66
    PRT_SENT_ALARM_DELAY,//67
    PRT_SET_ALARM_DELAY_TIME,//设置闹钟延时提醒时间68  单位为分钟
    PRT_GET_ALARM_DELAY_TIME,//69
    PRT_SENT_ALARM_DELAY_TIME,//6A
    PRT_SET_TOMATO_SOUND,//设置番茄时钟提示音6B  1开 0 关
    PRT_GET_TOMATO_SOUND,//6C
    PRT_SENT_TOMATO_SOUND,//6D
    PRT_SET_SUSPEND_TIME,//设置熄屏时间6E        单位为秒
    PRT_GET_SUSPEND_TIME,//6F
    PRT_SENT_SUSPEND_TIME,//70
    PRT_SET_TOMATO_WORK_TIME,//设置番茄时钟工作时间71单位为分钟
    PRT_GET_TOMATO_WORK_TIME,//72
    PRT_SENT_TOMATO_WORK_TIME,//73
    PRT_SET_TOMATO_BREAK_TIME,//设置番茄时钟休息时间74单位为分钟
    PRT_GET_TOMATO_BREAK_TIME,//75
    PRT_SENT_TOMATO_BREAK_TIME,//76
    PRT_SET_ALARM_TIME,//设置闹钟时间77
    PRT_SET_SCREEN_FLASH,//设置屏幕闪烁 78  1开 0 关
    PRT_GET_SCREEN_FLASHE,//79
    PRT_SENT_SCREEN_FLASH,//7A
    PRT_GET_TOMATO_COUNT,//7B    获取番茄钟计数数据
    PRT_SENT_TOMATO_COUNT,//7C
    PRT_GET_ALARM_TIME,//7D       获取闹钟数据
    PRT_SENT_ALARM_TIME,//7E

    PRT_GET_BT_VERSION, //app 获取打印机蓝牙版本 7F
    PRT_SENT_BT_VERSION,//获取打印机机器码 80
    PRT_GET_PRINTER_MACHINE_CODE = 0x81, // app 获取打印机机器码 81
    PRT_SENT_PRINTER_MACHINE_CODE = 0x82,//获取打印机机器码 82
    PRT_SET_ALARM_SOUND_TYPE = 0x83,//83 提醒声音选择 范围 0-4 ，5 种
    PRT_GET_ALARM_SOUND_TYPE = 0x84,//84
    PRT_SENT_ALARM_SOUND_TYPE = 0x85,//85
    PRT_ALARM_SOUND_PLAY,//86
    PRT_ALARM_SOUND_PLAY_STOP,//87
    PRT_SET_NOTE_PRE_ACTION,//88 无需数据
    PRT_SET_POWER_OFF_ALARM,//89 关机闹钟开关，1 开 0 关
    PRT_GET_POWER_OFF_ALARM,//8A
    PRT_SENT_POWER_OFF_ALARM,//8B
    
    PRT_SET_GRAYSCALE = 0xD0,
    
    PRT_MAX_CMD,
};

typedef enum {
    PRT_PROTOCOL_OK = 0, ///<协议解析正常
    PRT_PROTOCOL_TIME_OUT,///<数据接收超时
    PRT_PROTOCOL_LEN_ERROR,///<数据长度错误
    PRT_PROTOCOL_CRC_ERROR,///<crc校验失败
    PRT_CMD_FORMAT_ERROR,///<指令格式有误
    PRT_DATA_OVER_FLOW,///<数据长度太大
} protocol_status_t;


#endif /* PRT_DEFINE_h */
