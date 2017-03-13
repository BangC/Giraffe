
#pragma once

#include "../Base/Type.h"

#include "GameRole.h"

namespace Giraffe
{
	class GameRoleMng : public BaseObjectMng<GameRole>, public CInstance<GameRoleMng>
	{
	public:
		GameRoleMng();
		virtual ~GameRoleMng();

	public:
		virtual void ShowDebug();

	protected:
	};
}