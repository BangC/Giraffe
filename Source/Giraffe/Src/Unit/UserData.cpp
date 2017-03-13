
#include "../Base/Type.h"

#include "UserData.h"

namespace Giraffe
{
	UserData::UserData()
		: myDecks(new DeckMng)
	{

	}
	UserData::~UserData()
	{

	}

	Bool8 UserData::LoadJson(JsonData &jsonData)
	{

		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
		name = StringConv(jsonData["UserName"].get<AString>());
		displayName = name;

		myDecks->LoadJson(jsonData["Decks"]);
	}

	void UserData::ShowDebug()
	{

		LOG(INFO) << "[UserData]";
		BaseObject::ShowDebug();

		myDecks->ShowDebug();
	}
}