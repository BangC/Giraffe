
#pragma once


#include "../Base/Type.h"

#include "DeckMng.h"

namespace Giraffe
{
	class UserData : public BaseObject
	{
	public:
		UserData();
		virtual ~UserData();
	protected:
		SharedPtr<DeckMng> myDecks;

	};
}
