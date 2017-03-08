
#pragma once


#include "../Base/Type.h"

#include "../Unit/UserData.h"

namespace Giraffe
{
	class GameDataPlay : public BaseObject
	{
	public:
		GameDataPlay();
		virtual ~GameDataPlay();
	protected:
		Vector<SharedPtr<UserData>> userList;
	};
}