
#pragma once

#include "../Base/Type.h"



namespace Giraffe
{
	class CardInfo;
	class CardUnit : public BaseObject, public JsonLoader
	{
	public:
		CardUnit();
		CardUnit(WeakPtr<CardInfo> infoDataSuper);
		virtual ~CardUnit();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	public:
		Bool8 SetBaseCard();

	protected:
		WeakPtr<CardInfo> infoData;
		Bool8 goldFome;
	};
}