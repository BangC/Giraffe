
#pragma once


#include "../Base/Type.h"

#include "../Unit/GameRole.h"
#include "../Unit/UserData.h"

namespace Giraffe
{
	class GameSimulator : public BaseObject, public JsonLoader
	{
	public:
		GameSimulator();
		virtual ~GameSimulator();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);


	protected:
		WeakPtr<GameRole> gameRole;
		Vector<WeakPtr<UserData>> playUsers; // BaseLinkMng
	};
}