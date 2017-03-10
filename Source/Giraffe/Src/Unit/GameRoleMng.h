
#pragma once

#include "../Base/Type.h"

#include "GameRole.h"

namespace Giraffe
{
	class GameRoleMng : public BaseObjectMng<GameRole, GameRoleMng>
	{
	public:
		GameRoleMng();
		virtual ~GameRoleMng();

	public:
		virtual void ShowDebug();

	protected:
	};
}