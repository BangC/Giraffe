
#include "../Base/Type.h"

#include "GameDataPlay.h"

namespace Giraffe
{
	GameDataPlay::GameDataPlay()
	{

	}

	GameDataPlay::~GameDataPlay()
	{
	}

	Bool8 GameDataPlay::LoadJson(JsonData &jsonData)
	{
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
		return true;
	}

	void GameDataPlay::ShowDebug()
	{
		LOG(INFO) << "[GameDataPlay]";
		BaseObject::ShowDebug();
	}
}