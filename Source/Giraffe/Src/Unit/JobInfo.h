
#pragma once


#include "../Base/Type.h"


namespace Giraffe
{
	class JobInfo
	{
	public:
		JobInfo();
		virtual ~JobInfo();
	protected:
		SharedPtr<CardInfo> cardInfo;
	};
}