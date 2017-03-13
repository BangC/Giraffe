

#pragma once

#include "Type.h"


namespace Giraffe
{
	class VersionData : public BaseObject, public JsonLoader
	{
	public:
		VersionData(Int32 Major = 0, Int32 Minor = 0, Int32 Revision = 0);
		virtual ~VersionData();

	public:
		bool operator == (const VersionData &rRef) const;
		bool operator != (const VersionData &rRef) const;

	public:
		virtual Bool8 LoadJson(JsonData &jsonData);
		virtual void ShowDebug();

	protected:
		Int32 major;
		Int32 minor;
		Int32 revision;

	};


}