

#pragma once


#include "Base/Type.h"

#include "Platform\GameSimulator.h"
#include "Platform\GameDataSystem.h"


#ifdef GIRAFFE_EXPORTS
#define DLL_Module __declspec(dllexport)
#else // GIRAFFE_EXPORTS
#define DLL_Module __declspec(dllimport)
#endif // GIRAFFE_EXPORTS
//#define DLL_Module 

int DLL_Module WorkMain(Giraffe::AString jsonString);

//bool LoadDll()



namespace Giraffe
{
	class GiraffeMain : public BaseObject, public JsonLoader
	{
	public:
		GiraffeMain();
		virtual ~GiraffeMain();

	public:
		virtual bool LoadJson(JsonData &jsonData);
	protected:
		SharedPtr<GameSimulator> gameSimulator;
		SharedPtr<GameDataSystem> gameData;
	};
}