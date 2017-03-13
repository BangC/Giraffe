
#pragma once

#include "../Base/Type.h"

#include "Deck.h"

namespace Giraffe
{
	class DeckMng : public BaseObjectMng<Deck>, public CInstance<DeckMng>
	{
	public:
		DeckMng();
		virtual ~DeckMng();

	public:
		virtual void ShowDebug();

	protected:
	};
}