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
#else
#include <stdlib.h>
#include <stdio.h>
#endif


#include "nfd.h"

#ifdef _WIN32
bool isSupportedInOS = true;
std::string pathSlash = "\\";
#else
#include <Adobe AIR/Adobe AIR.h>
bool isSupportedInOS = true;
std::string pathSlash = "/";
#endif

#include <ANEhelper.h>
ANEHelper aneHelper = ANEHelper();

extern "C" {
    FREContext dllContext;
	
	FREObject saveAs(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
		nfdchar_t *outPath = nullptr;

		auto result = NFD_SaveDialog(aneHelper.getString(argv[0]).c_str(), aneHelper.getString(argv[1]).c_str(), &outPath);
		if (result == NFD_OKAY) {
		} else if (result == NFD_CANCEL) {
			outPath = "";
		} else {
			outPath = "";
		}
		
		return aneHelper.getFREObject(outPath);
	}
	
	void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet) {
		static FRENamedFunction extensionFunctions[] = {
			{ reinterpret_cast<const uint8_t*>("saveAs"),nullptr, &saveAs }
		};
		
		*numFunctionsToSet = sizeof(extensionFunctions) / sizeof(FRENamedFunction);
		*functionsToSet = extensionFunctions;
		dllContext = ctx;
	}
	
	
	void contextFinalizer(FREContext ctx) { }
	
	void TRSAAExtInizer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
		*ctxInitializer = &contextInitializer;
		*ctxFinalizer = &contextFinalizer;
	}
	
	void TRSAAExtFinizer(void* extData) {
		FREContext nullCTX = nullptr;
		contextFinalizer(nullCTX);
	}
	
}
