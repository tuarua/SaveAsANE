//
//  SaveAsANE.cpp
//  SaveAsANE
//
//  Created by User on 30/10/2016.
//  Copyright © 2016 Tua Rua Ltd. All rights reserved.
//
#include "SaveAsANE.h"

#include <sstream>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <stdlib.h>
#include <stdio.h>
#endif


#include "nfd.h"

#include "ANEhelper.h"

#ifdef _WIN32
#include "FlashRuntimeExtensions.h"
bool isSupportedInOS = true;
std::string pathSlash = "\\";
#else
#include <Adobe AIR/Adobe AIR.h>
bool isSupportedInOS = true;
std::string pathSlash = "/";
#endif


extern "C" {
    FREContext dllContext;
	
	
	FREObject saveAs(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
		nfdchar_t *outPath = NULL;
		nfdresult_t result = NFD_SaveDialog(getStringFromFREObject(argv[0]).c_str(), getStringFromFREObject(argv[1]).c_str(), &outPath);
		if (result == NFD_OKAY) {
		}
		else if (result == NFD_CANCEL) {
			outPath = "";
		}
		else {
			outPath = "";
		}
		return getFREObjectFromString(outPath);
	}
	
	void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet) {
		static FRENamedFunction extensionFunctions[] = {
			{ (const uint8_t*) "saveAs",NULL, &saveAs }
		};
		
		*numFunctionsToSet = sizeof(extensionFunctions) / sizeof(FRENamedFunction);
		*functionsToSet = extensionFunctions;
		dllContext = ctx;
	}
	
	
	void contextFinalizer(FREContext ctx) {
		return;
	}
	
	void TRSAAExtInizer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
		*ctxInitializer = &contextInitializer;
		*ctxFinalizer = &contextFinalizer;
	}
	
	void TRSAAExtFinizer(void* extData) {
		FREContext nullCTX;
		nullCTX = 0;
		contextFinalizer(nullCTX);
		return;
	}
	
}
