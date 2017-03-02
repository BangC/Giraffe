
#pragma once

#include "../Base/Type.h"

#include "CardUnit.h"

namespace Giraffe
{

	class Deck
	{
		Deck();
		virtual ~Deck();

		Vector<SharedPtr<CardUnit>> cardList;
	};
}