
#pragma once


#include "../Base/Type.h"

#include "../Unit/UserData.h"

namespace Giraffe
{
	class GameDataPlay : public BaseObject, public JsonLoader
	{
	public:
		GameDataPlay();
		virtual ~GameDataPlay();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		Vector<SharedPtr<UserData>> userList;
	};
}