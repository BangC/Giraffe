
#pragma once


#include "../Base/Type.h"

#include "../Unit/GameRoleMng.h"
#include "../Unit/CardInfoMng.h"
#include "../Unit/JobMng.h"

namespace Giraffe
{
	class GameDataSystem : public BaseObject
	{
	public:
		GameDataSystem();
		virtual ~GameDataSystem();
	protected:
		SharedPtr<GameRoleMng> gameRoles;
		SharedPtr<JobMng> jobMng;
		SharedPtr<CardInfoMng> cardInfoMng;
	};
}