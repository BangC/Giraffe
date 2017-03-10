
#pragma once

#include "../Base/Type.h"

#include "GameRole.h"

namespace Giraffe
{
	class JobInfo;

	class CardInfo : public BaseObject, public JsonLoader
	{
	public:
		CardInfo();
		virtual ~CardInfo();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		WeakPtr<JobInfo> usingJob;
		Vector<WeakPtr<GameRole>> ableRoles;
	};
}