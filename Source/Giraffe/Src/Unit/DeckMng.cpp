#include "../Base/Type.h"

#include "DeckMng.h"

namespace Giraffe
{


	DeckMng::DeckMng()
	{

	}

	DeckMng::~DeckMng()
	{

	}

	void DeckMng::ShowDebug()
	{
		LOG(INFO) << "[DeckMng]";
		BaseObject::ShowDebug();

		BaseObjectMng<Deck, DeckMng>::ShowDebug();
	}
}