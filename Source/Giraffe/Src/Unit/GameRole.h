
#pragma once

#include "../Base/Type.h"

#include "CardInfoMng.h"
#include "JobMng.h"

namespace Giraffe
{
	class GameRole
	{
	public:
		GameRole();
		virtual ~GameRole();
	protected:
		SharedPtr<JobMng> jobList;

		std::shared_ptr<CardInfoMng> cardInfoList;
	};
}