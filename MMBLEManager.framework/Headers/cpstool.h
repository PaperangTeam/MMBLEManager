//
//  cpstool.h
//  Paperang
//
//  Created by hoho on 24/03/2018.
//  Copyright © 2018 Hoho. All rights reserved.
//

#ifndef cpstool_h
#define cpstool_h

#include <stdio.h>
#include "minilzo.h"


#ifdef __cplusplus
extern "C" {

#endif

    
#define IN_LEN      (1024ul)//(128*1024ul)
#define OUT_LEN     (IN_LEN + IN_LEN / 16 + 64 + 3)
    
    static unsigned char __LZO_MMODEL inB  [ IN_LEN ];
    static unsigned char __LZO_MMODEL outB [ OUT_LEN ];
    
    
#define HEAP_ALLOC(var,size) \
lzo_align_t __LZO_MMODEL var [ ((size) + (sizeof(lzo_align_t) - 1)) / sizeof(lzo_align_t) ]
    
//    static HEAP_ALLOC(wrkmem, LZO1X_1_MEM_COMPRESS);

    
#define byte unsigned char
int compress(void *src, unsigned src_len, void *dst);
int decompress(void *src, unsigned src_len, void *dst);
#ifdef __cplusplus
}
#endif
#endif /* cpstool_h */
