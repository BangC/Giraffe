
#pragma once


#include "../Base/Type.h"

#include "DeckMng.h"

namespace Giraffe
{
	class UserData : public BaseObject, public JsonLoader
	{
	public:
		UserData();
		virtual ~UserData();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		SharedPtr<DeckMng> myDecks;

	};
}
