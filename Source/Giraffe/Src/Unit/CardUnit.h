
#pragma once

#include "../Base/Type.h"

#include "CardInfo.h"


namespace Giraffe
{
	class CardUnit : public BaseObject
	{
	public:
		CardUnit();
		virtual ~CardUnit();

	protected:
		SharedPtr<CardInfo> infoData;
	};
}