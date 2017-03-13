#include "../Base/Type.h"

#include "JobMng.h"

namespace Giraffe
{
	JobMng::JobMng()
	{
	}

	JobMng::~JobMng()
	{
	}


	void JobMng::ShowDebug()
	{

		LOG(INFO) << "[JobMng]";
		BaseObject::ShowDebug();

		BaseObjectMng<JobInfo>::ShowDebug();
	}

}
