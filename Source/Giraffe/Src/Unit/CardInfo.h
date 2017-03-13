
#pragma once

#include "../Base/Type.h"

#include "GameRole.h"
#include "CardUnit.h"


namespace Giraffe
{
	class JobInfo;

	class CardInfo : public BaseObject, public JsonLoader, public std::enable_shared_from_this<CardInfo>
	{
	public:
		CardInfo();
		virtual ~CardInfo();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		Vector<WeakPtr<JobInfo>> needJob;
		Vector<WeakPtr<GameRole>> ableRoles;

		BaseObjectMng<CardUnit> formMng;
	};
}