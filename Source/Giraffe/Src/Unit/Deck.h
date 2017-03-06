
#pragma once

#include "../Base/Type.h"

#include "JobInfo.h"
#include "CardUnit.h"

namespace Giraffe
{

	class Deck : public BaseObject
	{
		Deck();
		virtual ~Deck();

		SharedPtr<JobInfo> myJob;
		Vector<SharedPtr<CardUnit>> cardList;
	};
}