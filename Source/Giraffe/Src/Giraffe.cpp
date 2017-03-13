


#include "Giraffe.h"




int DLL_Module WorkMain(Giraffe::AString &jsonString)
{


	Giraffe::GiraffeMain gMain;

	auto loadResult = gMain.LoadJsonFromString(jsonString);
	if (!loadResult)
	{
		return 1;
	}

	gMain.ShowDebug();

	return 0;
}


namespace Giraffe
{
	GiraffeMain::GiraffeMain()
		: gameSimulator(new GameSimulator)
		, gameData(new GameDataSystem)
		, gameDataPlay(new GameDataPlay)
		, versionData(new VersionData)
	{
	}
	GiraffeMain::~GiraffeMain()
	{

	}

	Bool8 GiraffeMain::LoadJson(JsonData &jsonData)
	{
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
// 		LOG(INFO) << "GiraffeMain::jsonData.dump()" << jsonData.dump();
		auto jData = jsonData["Giraffe"];
		name = StringConv(jData["Name"].get<AString>());

		auto loadResult = versionData->LoadJson(jData["Version"]);
		if (!loadResult)
		{
			return loadResult;
		}

// 		loadResult = gameSimulator->LoadJson(jData["Dynamic"]);
// 		if (!loadResult)
// 		{
// 			return loadResult;
// 		}

		loadResult = gameData->LoadJson(jData["Static"]);
		if (!loadResult)
		{
			return loadResult;
		}

		loadResult = gameDataPlay->LoadJson(jData["Dynamic"]);
		if (!loadResult)
		{
			return loadResult;
		}

		return loadResult;
	}

	void GiraffeMain::ShowDebug()
	{
		LOG(INFO) << "[GiraffeMain]";

		BaseObject::ShowDebug();

		versionData->ShowDebug();
		gameSimulator->ShowDebug();
		gameData->ShowDebug();
	}





}