//
//  MMNetworkManager.h
//  MMApi
//
//  Created by hoho on 2017/11/8.
//  Copyright © 2017年 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MMNetworkManager : NSObject

+ (instancetype)shared;

- (void)POSTWithParameters:(NSDictionary *)aParameters
                   request:(NSString *)request
           completionBlock:(void (^)(NSDictionary *dic))block
              failureBlock:(void (^)(NSInteger code, NSString *description))failureBlock;

- (void)registWithAppID:(long)appId
                  AppKey:(NSString *)appKey
               andSecret:(NSString *)secret
                 success:(void (^)(void))success
                   fail:(void (^)(NSError *error))fail;
@end
