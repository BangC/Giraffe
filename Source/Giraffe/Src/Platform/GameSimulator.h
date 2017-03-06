
#pragma once


#include "../Base/Type.h"

#include "../Unit/GameRole.h"
#include "../Unit/UserData.h"

namespace Giraffe
{
	class GameSimulator : public BaseObject
	{
	public:
		GameSimulator();
		virtual ~GameSimulator();
	protected:
		WeakPtr<GameRole> gameRole;
		Vector<WeakPtr<UserData>> playUsers;
	};
}