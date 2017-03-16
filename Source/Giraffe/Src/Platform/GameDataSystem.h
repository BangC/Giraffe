
#pragma once


#include "../Base/Type.h"

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
// 		GameRoleMng::CreateInstance();
// 		JobMng::CreateInstance();
// 		CardInfoMng::CreateInstance();
	};
}