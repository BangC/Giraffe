#include "../Base/Type.h"

#include "GameRole.h"

namespace Giraffe
{
	GameRole::GameRole()
	{

	}
	GameRole::~GameRole()
	{

	}

	Bool8 GameRole::LoadJson(JsonData &jsonData)
	{
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
		name = StringConv(jsonData["RoleName"].get<AString>());
		displayName = name;

		return true;
	}
	void GameRole::ShowDebug()
	{
		LOG(INFO) << "[GameRole]";
		BaseObject::ShowDebug();
	}
}
