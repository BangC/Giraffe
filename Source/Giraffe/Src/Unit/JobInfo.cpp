
#include "../Base/Type.h"

#include "JobInfo.h"

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
