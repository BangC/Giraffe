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

		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
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