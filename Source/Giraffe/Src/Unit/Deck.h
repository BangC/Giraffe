
#pragma once

#include "../Base/Type.h"

#include "JobInfo.h"
#include "CardUnit.h"

namespace Giraffe
{

	class Deck : public BaseObject, public JsonLoader
	{
	public:
		Deck();
		virtual ~Deck();


	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		SharedPtr<JobInfo> myJob;
		Vector<WeakPtr<CardUnit>> cardList;
	};
}