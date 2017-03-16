
#include "../Base/Type.h"

#include "GameDataSystem.h"

#include "../Unit/GameRoleMng.h"
#include "../Unit/CardInfoMng.h"
#include "../Unit/JobMng.h"

namespace Giraffe
{
	GameDataSystem::GameDataSystem()
	{
		GameRoleMng::CreateInstance();
		JobMng::CreateInstance();
		CardInfoMng::CreateInstance();
	}

	GameDataSystem::~GameDataSystem()
	{
	}


	Bool8 GameDataSystem::LoadJson(JsonData &jsonData)
	{
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
// 		LOG(INFO) << "GameDataSystem::jsonData.dump()" << jsonData.dump();

		Bool8 returnResult = false;

		returnResult = GameRoleMng::GetInstance()->LoadJson(jsonData["Roles"]);
		if (!returnResult)
		{
			return returnResult;
		}

		returnResult = JobMng::GetInstance()->LoadJson(jsonData["Jobs"]);
		if (!returnResult)
		{
			return returnResult;
		}

		returnResult = CardInfoMng::GetInstance()->LoadJson(jsonData["Cards"]);
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

		GameRoleMng::GetInstance()->ShowDebug();
		JobMng::GetInstance()->ShowDebug();
		CardInfoMng::GetInstance()->ShowDebug();
	}
}