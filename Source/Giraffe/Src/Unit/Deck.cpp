#include "../Base/Type.h"

#include "Deck.h"

namespace Giraffe
{

	Deck::Deck()
	{

	}

	Deck::~Deck()
	{

	}

	Bool8 Deck::LoadJson(JsonData &jsonData)
	{

		name = StringConv(jsonData["DackName"].get<AString>());
		displayName = name;

		return true;
	}
	void Deck::ShowDebug()
	{


		LOG(INFO) << "[Deck]";
		BaseObject::ShowDebug();
	}
}