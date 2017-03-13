

#pragma once


#include "Base/Type.h"
#include "Base/Version.h"

#include "Platform\GameSimulator.h"
#include "Platform\GameDataSystem.h"
#include "Platform\GameDataPlay.h"


#ifdef GIRAFFE_EXPORTS
#define DLL_Module __declspec(dllexport)
#else // GIRAFFE_EXPORTS
#define DLL_Module __declspec(dllimport)
#endif // GIRAFFE_EXPORTS
//#define DLL_Module 

int DLL_Module WorkMain(Giraffe::AString &jsonString);

//bool LoadDll()



namespace Giraffe
{
	class GiraffeMain : public BaseObject, public JsonLoader
	{
	public:
		GiraffeMain();
		virtual ~GiraffeMain();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();


	protected:
		SharedPtr<GameSimulator> gameSimulator;
		SharedPtr<GameDataSystem> gameData;
		SharedPtr<GameDataPlay> gameDataPlay;

		SharedPtr<VersionData> versionData;
	};
}