


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
	{
		google::InitGoogleLogging("Giraffe_Test");
		google::SetLogDestination(google::GLOG_INFO, "./Test.");
		//google::SetLogFilenameExtension(".BC.log");
		google::LogToStderr();
	}
	GiraffeMain::~GiraffeMain()
	{

	}

	Bool8 GiraffeMain::LoadJson(JsonData &jsonData)
	{
// 		LOG(INFO) << "GiraffeMain::jsonData.dump()" << jsonData.dump();
		auto jData = jsonData["Giraffe"];
		name = StringConv(jData["Name"].get<AString>());

		auto loadResult = gameSimulator->LoadJson(jData["Dynamic"]);
		if (!loadResult)
		{
			return loadResult;
		}
		loadResult = gameData->LoadJson(jData["Static"]);
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
		gameSimulator->ShowDebug();
		gameData->ShowDebug();
	}





}