
#pragma once

#include "../Base/Type.h"

namespace Giraffe
{
	class JobInfo;

	class CardInfo
	{
	public:
		CardInfo();
		virtual ~CardInfo();
	protected:
		WeakPtr<JobInfo> usingJob;
	};
}