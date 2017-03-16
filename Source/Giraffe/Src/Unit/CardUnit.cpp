
#include "../Base/Type.h"

#include "CardUnit.h"
#include "CardInfo.h"

namespace Giraffe
{

	CardUnit::CardUnit()
	{
		throw 1;
	}

	CardUnit::CardUnit(WeakPtr<CardInfo> infoDataSuper)
		: infoData(infoDataSuper)
		, goldFome(false)
	{

	}
	CardUnit::~CardUnit()
	{

	}

	Bool8 CardUnit::LoadJson(JsonData &jsonData)
	{
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}

		name = StringConv(jsonData["CardFormName"].get<AString>());
		displayName = name;
		
		if (jsonData["Gold"])
		{
			goldFome = true;
		}

		return true;
	}

	void CardUnit::ShowDebug()
	{
		LOG(INFO) << "[CardUnit]";
		BaseObject::ShowDebug();

		LOG(INFO) << "GoldForm : " << goldFome;
	}

	Bool8 CardUnit::SetBaseCard()
	{
		auto baseInfo = infoData.lock();
		name = baseInfo->GetName() + StringConv(".Base");
		displayName = name;
		return true;
	}



}