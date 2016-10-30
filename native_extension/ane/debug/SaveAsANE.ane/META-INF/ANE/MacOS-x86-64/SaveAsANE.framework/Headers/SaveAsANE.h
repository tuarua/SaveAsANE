//
//  SaveAsANE.h
//  SaveAsANE
//
//  Created by User on 30/10/2016.
//  Copyright © 2016 Tua Rua Ltd. All rights reserved.
//

#ifdef _WIN32
#include "FlashRuntimeExtensions.h"
extern "C" {
    __declspec(dllexport) void TRSAAExtInizer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
    __declspec(dllexport) void TRSAAExtFinizer(void* extData);
}
#else
#include <stdio.h>
#include <Adobe AIR/Adobe AIR.h>

#define EXPORT __attribute__((visibility("default")))
extern "C" {
    EXPORT
    void TRSAAExtInizer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
    
    EXPORT
    void TRSAAExtFinizer(void* extData);
}
#endif
