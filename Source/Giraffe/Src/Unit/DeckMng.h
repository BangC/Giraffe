
#pragma once

#include "../Base/Type.h"

#include "Deck.h"

namespace Giraffe
{
	class DeckMng
	{
	public:
		DeckMng();
		virtual ~DeckMng();

	protected:
		Vector<SharedPtr<Deck>> deckList;
	};
}