
#pragma once


#include "../Base/Type.h"

#include "../Unit/GameRoleMng.h"
#include "../Unit/CardInfoMng.h"
#include "../Unit/JobMng.h"

namespace Giraffe
{
	class GameDataSystem : public BaseObject, public JsonLoader
	{
	public:
		GameDataSystem();
		virtual ~GameDataSystem();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();


	protected:
		SharedPtr<GameRoleMng> gameRoles;
		SharedPtr<JobMng> jobMng;
		SharedPtr<CardInfoMng> cardInfoMng;
	};
}