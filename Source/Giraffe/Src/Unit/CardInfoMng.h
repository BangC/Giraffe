
#pragma once

#include "../Base/Type.h"

#include "CardInfo.h"


namespace Giraffe
{
	class CardInfoMng : public BaseObjectMng<CardInfo>
	{
	public:
		CardInfoMng();
		virtual ~CardInfoMng();

	public:
		virtual void ShowDebug();

	protected:
	};
}