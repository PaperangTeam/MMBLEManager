//
//  MMPrintCompressTool.h
//  Paperang
//
//  Created by hoho on 2019/7/24.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "cpstool.h"
//#import "MMImageLib.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MMPrintCompressType) {
    MMPrintCompressTypeLZO,
    MMPrintCompressTypeHFM,
    
};

@interface MMPrintCompressTool : NSObject

+ (NSData *)lzo_compressData:(NSData *)data;

+ (NSData *)compressData:(NSData *)data withHFMData:(NSData *)hfmTreeData;

@end

NS_ASSUME_NONNULL_END
