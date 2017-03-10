

#pragma once


#include <vector>
#include <memory>
#include <string>

#include <locale>
#include <codecvt>

#include "../../../3rdParty/json/src/json.hpp"

#include "log.h"


namespace Giraffe
{


	typedef int Int32;
	typedef long long Int64;
	typedef float Float32;
	typedef double Float64;

	typedef bool Bool8;

	typedef unsigned int Size32;
	typedef unsigned long long Size64;

	template<typename DataType>
	using Vector = std::vector<DataType>;

	template<typename DataType>
	using SharedPtr = std::shared_ptr<DataType>;
	template<typename DataType>
	using WeakPtr = std::weak_ptr<DataType>;

	typedef std::wstring String;
	typedef std::string AString;

	String StringConv(const AString& str);
	AString StringConv(const String& wstr);

	using JsonData = nlohmann::json;

	class BaseObject
	{
	public:
		BaseObject();
		virtual ~BaseObject();

	public:
		virtual void ShowDebug();

	protected:
		String name;
		String displayName;
		//String uniqueKey;
	};

	template<typename TypeData>
	class BaseObjectMng : public BaseObject, public JsonLoader
	{
	public:
		BaseObjectMng()
		{

		}
		virtual ~BaseObjectMng()
		{

		}

		Bool8 Resize(Size32 nextSize)
		{
			if (dataList.size() >= nextSize)
			{
				return false;
			}
			dataList.resize(nextSize);
		}

		virtual Bool8 LoadJson(JsonData &jArray)
		{
			Bool8 returnResult = false;
			dataList.resize(jArray.size());
			auto dataIter = dataList.begin();

			for (auto& element : jArray)
			{
				dataIter->reset(new TypeData);
				returnResult = (*dataIter)->LoadJson(element);
				if (!returnResult)
				{
					return returnResult;
				}
				++dataIter;
			}
			return returnResult;
		}

		virtual void ShowDebug()
		{
			for (auto& dataOne : dataList)
			{
				dataOne->ShowDebug();
			}
		}
	protected:
		Vector<SharedPtr<TypeData>> dataList;
	};

	class JsonLoader
	{
	public:
		JsonLoader();
		virtual ~JsonLoader();

		virtual Bool8 LoadJsonFromString(AString &jsonString);
		virtual Bool8 LoadJson(JsonData &jsonData) = 0;
	protected:
	};

	/*
	부족한것 만들어야할것

	. 버전
	. 싱글턴
	*/

}
