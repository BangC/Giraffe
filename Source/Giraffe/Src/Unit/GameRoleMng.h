
#pragma once

#include "../Base/Type.h"

#include "GameRole.h"

namespace Giraffe
{
	class GameRoleMng : public BaseObject
	{
	public:
		GameRoleMng();
		virtual ~GameRoleMng();

	protected:
		Vector<SharedPtr<GameRole>> roleList;
	};
}