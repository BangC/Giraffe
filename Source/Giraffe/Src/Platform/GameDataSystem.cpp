
#include "../Base/Type.h"

#include "GameDataSystem.h"

namespace Giraffe
{
	GameDataSystem::GameDataSystem()
		: gameRoles(new GameRoleMng)
		, jobMng(new JobMng)
		, cardInfoMng(new CardInfoMng)
	{

	}

	GameDataSystem::~GameDataSystem()
	{
	}


	Bool8 GameDataSystem::LoadJson(JsonData &jsonData)
	{
// 		LOG(INFO) << "GameDataSystem::jsonData.dump()" << jsonData.dump();

		Bool8 returnResult = false;

		returnResult = gameRoles->LoadJson(jsonData["Roles"]);
		if (!returnResult)
		{
			return returnResult;
		}

		returnResult = jobMng->LoadJson(jsonData["Jobs"]);
		if (!returnResult)
		{
			return returnResult;
		}

		returnResult = cardInfoMng->LoadJson(jsonData["Cards"]);
		if (!returnResult)
		{
			return returnResult;
		}

		return true;
	}

	void GameDataSystem::ShowDebug()
	{

		LOG(INFO) << "[GameDataSystem]";
		BaseObject::ShowDebug();
		gameRoles->ShowDebug();
		jobMng->ShowDebug();
		cardInfoMng->ShowDebug();
	}
}