
#pragma once


#include "../Base/Type.h"

#include "../Unit/GameRole.h"
#include "../Unit/UserData.h"

namespace Giraffe
{
	class GameSimulator
	{
	public:
		GameSimulator();
		virtual ~GameSimulator();
	protected:
		SharedPtr<GameRole> gameRole;
		Vector<SharedPtr<UserData>> userList;
	};
}