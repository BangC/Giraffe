#include "../Base/Type.h"

#include "CardInfo.h"

#include "JobInfo.h"
#include "GameRoleMng.h"

#include "CardInfo.h"
#include "JobMng.h"


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
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}

		name = StringConv(jsonData["CardName"].get<AString>());
		displayName = name;

		ableRoles.LoadJson(jsonData["AbleRole"]);
		
		auto thisPtr = shared_from_this();

		SharedPtr<CardUnit> baseUnit(new CardUnit(thisPtr));
		baseUnit->SetBaseCard();
		formMng.Append(baseUnit);

		formMng.LoadJson(jsonData["AbleForms"], thisPtr);


		needJob.LoadJson(jsonData["NeedJob"]);

		return true;
	}
	void CardInfo::ShowDebug()
	{
		LOG(INFO) << "[CardInfo]";
		BaseObject::ShowDebug();

		LOG(INFO) << "AbleRoles >";
		ableRoles.ShowDebug();

		LOG(INFO) << "needJobs >";
		needJob.ShowDebug();


		formMng.ShowDebug();
	}

}