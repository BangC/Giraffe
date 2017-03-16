
#pragma once

#include "../Base/Type.h"

#include "GameRoleMng.h"
#include "CardUnit.h"
#include "JobMng.h"


namespace Giraffe
{
	//class JobMng;

	class CardInfo : public BaseObject, public JsonLoader, public std::enable_shared_from_this<CardInfo>
	{
	public:
		CardInfo();
		virtual ~CardInfo();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		BaseLinkMng<JobMng> needJob;
		BaseLinkMng<GameRoleMng> ableRoles;

		BaseObjectMng<CardUnit> formMng;
	};
}