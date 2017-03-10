#include "../Base/Type.h"

#include "CardInfo.h"

#include"JobInfo.h"
namespace Giraffe
{

	CardInfo::CardInfo()
	{

	}

	CardInfo::~CardInfo()
	{

	}

	Bool8 CardInfo::LoadJson(JsonData &jsonData)
	{

		name = StringConv(jsonData["CardName"].get<AString>());
		displayName = name;

		return true;
	}
	void CardInfo::ShowDebug()
	{


		LOG(INFO) << "[CardInfo]";
		BaseObject::ShowDebug();
	}

}