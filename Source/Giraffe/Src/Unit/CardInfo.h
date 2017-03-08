
#pragma once

#include "../Base/Type.h"

#include "GameRole.h"

namespace Giraffe
{
	class JobInfo;

	class CardInfo : public BaseObject
	{
	public:
		CardInfo();
		virtual ~CardInfo();
	protected:
		WeakPtr<JobInfo> usingJob;
		Vector<WeakPtr<GameRole>> ableRoles;
	};
}