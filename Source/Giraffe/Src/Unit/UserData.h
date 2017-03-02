
#pragma once


#include "../Base/Type.h"

#include "JobInfo.h"
#include "DeckMng.h"

namespace Giraffe
{
	class UserData
	{
	public:
		UserData();
		virtual ~UserData();
	protected:
		SharedPtr<JobInfo> myJob;
		SharedPtr<DeckMng> myDecks;

	};
}
