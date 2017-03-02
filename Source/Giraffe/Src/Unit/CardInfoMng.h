
#pragma once

#include "../Base/Type.h"

#include "CardInfo.h"


namespace Giraffe
{
	class CardInfoMng
	{
	public:
		CardInfoMng();
		virtual ~CardInfoMng();

	protected:
		Vector<SharedPtr<CardInfo>> cardMap;
	};
}