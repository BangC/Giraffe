
#pragma once


#include "../Base/Type.h"

#include "JobInfo.h"

namespace Giraffe
{
	class JobMng : public BaseObject
	{
	public:
		JobMng();
		virtual ~JobMng();

	protected:
		Vector<SharedPtr<JobInfo>> jobList;
	};

}