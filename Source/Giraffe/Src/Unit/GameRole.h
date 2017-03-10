
#pragma once

#include "../Base/Type.h"


namespace Giraffe
{
	class GameRole : public BaseObject, public JsonLoader
	{
	public:
		GameRole();
		virtual ~GameRole();

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
	};
}