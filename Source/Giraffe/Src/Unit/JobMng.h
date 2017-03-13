
#pragma once


#include "../Base/Type.h"

#include "JobInfo.h"

namespace Giraffe
{
	class JobMng : public BaseObjectMng<JobInfo>, public CInstance<JobMng>
	{
	public:
		JobMng();
		virtual ~JobMng();

	public:
		virtual void ShowDebug();


	protected:
	};

}