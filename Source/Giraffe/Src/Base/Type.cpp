
#include "Type.h"


namespace Giraffe
{

	String StringConv(const AString& str)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.from_bytes(str);
	}

	AString StringConv(const String& wstr)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.to_bytes(wstr);
	}

	//////////////////////////////////////////////////////////////////////////

	BaseObject::BaseObject()
	{

	}
	BaseObject::~BaseObject()
	{

	}

	void BaseObject::ShowDebug()
	{
		if (!name.empty())
		{
			LOG(INFO) << "name : " << StringConv(name);
		}
		if (!displayName.empty())
		{
			LOG(INFO) << "displayName : " << StringConv(displayName);
		}
	}

	//////////////////////////////////////////////////////////////////////////

	JsonLoader::JsonLoader()
	{

	}
	JsonLoader::~JsonLoader()
	{

	}

	Bool8 JsonLoader::LoadJsonFromString(AString &jsonString)
	{
		auto jData = JsonData::parse(jsonString);
		return LoadJson(jData);
	}

	//////////////////////////////////////////////////////////////////////////

}