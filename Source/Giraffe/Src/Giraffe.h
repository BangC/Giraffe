

#pragma once


#include "Base/Type.h"


#ifdef GIRAFFE_EXPORTS
#define DLL_Module __declspec(dllexport)
#else // GIRAFFE_EXPORTS
#define DLL_Module __declspec(dllimport)
#endif // GIRAFFE_EXPORTS
//#define DLL_Module 

int DLL_Module WorkMain();

//bool LoadDll()