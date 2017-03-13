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

		auto &ableRoleDatas = jsonData["AbleRole"];
		ableRoles.resize(ableRoleDatas.size());
		auto roleIter = ableRoles.begin();

		for (auto &roleString : ableRoleDatas)
		{
			(*roleIter) = GameRoleMng::GetInstance()->GetDataFromName(roleString.get<AString>());
			++roleIter;
		}
		
		auto thisPtr = shared_from_this();
		formMng.LoadJson(jsonData["AbleForms"], thisPtr);


		auto &needJobDatas = jsonData["NeedJob"];
		needJob.resize(needJobDatas.size());
		auto jobIter = needJob.begin();

		for (auto &jobString : needJobDatas)
		{
			(*jobIter) = JobMng::GetInstance()->GetDataFromName(jobString.get<AString>());
			++jobIter;
		}

		return true;
	}
	void CardInfo::ShowDebug()
	{
		LOG(INFO) << "[CardInfo]";
		BaseObject::ShowDebug();

		LOG(INFO) << "AbleRoles >";
		if (ableRoles.empty())
		{
			LOG(INFO) << "  Empty";
		}
		else
		{
			for (auto &roleWptr : ableRoles)
			{
				auto role = roleWptr.lock();
				LOG(INFO) << "  " << StringConv(role->GetName());
			}
		}

		LOG(INFO) << "needJobs >";
		if (needJob.empty())
		{
			LOG(INFO) << "  Empty";
		}
		else
		{
			for (auto &jobWptr : needJob)
			{
				auto job = jobWptr.lock();
				LOG(INFO) << "  " << StringConv(job->GetName());
			}

		}


		formMng.ShowDebug();
	}

}