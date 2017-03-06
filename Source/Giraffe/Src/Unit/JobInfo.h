
#pragma once


#include "../Base/Type.h"


namespace Giraffe
{
	class JobInfo : public BaseObject
	{
	public:
		JobInfo();
		virtual ~JobInfo();
	protected:
		SharedPtr<CardInfo> cardInfo;
	};
}