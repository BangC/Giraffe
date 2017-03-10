#include "../Base/Type.h"

#include "GameRoleMng.h"

namespace Giraffe
{
	GameRoleMng::GameRoleMng()
	{

	}
	GameRoleMng::~GameRoleMng()
	{

	}

	void GameRoleMng::ShowDebug()
	{

		LOG(INFO) << "[GameRoleMng]";
		BaseObject::ShowDebug();
		BaseObjectMng<GameRole, GameRoleMng>::ShowDebug();
	}
}
