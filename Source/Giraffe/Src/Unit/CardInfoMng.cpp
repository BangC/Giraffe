#include "../Base/Type.h"

#include "CardInfoMng.h"

namespace Giraffe
{

	CardInfoMng::CardInfoMng()
	{

	}

	CardInfoMng::~CardInfoMng()
	{

	}


	void CardInfoMng::ShowDebug()
	{

		LOG(INFO) << "[CardInfoMng]";
		BaseObject::ShowDebug();

		BaseObjectMng<CardInfo>::ShowDebug();
	}
}