
#include "../Base/Type.h"

#include "JobInfo.h"
#include "CardInfo.h"

namespace Giraffe
{

	JobInfo::JobInfo()
	{

	}
	JobInfo::~JobInfo()
	{

	}

	Bool8 JobInfo::LoadJson(JsonData &jsonData)
	{
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
		name = StringConv(jsonData["JobName"].get<AString>());
		displayName = name;

		return true;
	}
	void JobInfo::ShowDebug()
	{

		LOG(INFO) << "[JobInfo]";
		BaseObject::ShowDebug();
	}
}
