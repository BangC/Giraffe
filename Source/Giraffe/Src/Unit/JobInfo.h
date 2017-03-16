
#pragma once


#include "../Base/Type.h"


namespace Giraffe
{
	class CardInfo;
	class JobInfo : public BaseObject, public JsonLoader
	{
	public:
		JobInfo();
		virtual ~JobInfo();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		SharedPtr<CardInfo> cardInfo;
	};
}