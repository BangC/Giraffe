

#pragma once


#include <vector>
#include <memory>
#include <string>

#include <locale>
#include <codecvt>

#include "../../../3rdParty/json/src/json.hpp"

#include "log.h"
#include "Instance.h"


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
	template<typename KeyType, typename DataType>
	using Map = std::map<KeyType, DataType>;

	template<typename DataType>
	using SharedPtr = std::shared_ptr<DataType>;
	template<typename DataType>
	using WeakPtr = std::weak_ptr<DataType>;

	typedef std::wstring String;
	typedef std::string AString;

	String StringConv(const AString& str);
	AString StringConv(const String& wstr);

	using JsonData = nlohmann::json;


	//////////////////////////////////////////////////////////////////////////

	const Int32 VersionMajor = 0;
	const Int32 VersionMinor = 0;
	const Int32 VersionRevision = 2;


	//////////////////////////////////////////////////////////////////////////

	class BaseObject
	{
	public:
		BaseObject();
		virtual ~BaseObject();

	public:
		virtual void ShowDebug();
		String GetName();

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
				dataMap[(*dataIter)->GetName()] = (*dataIter);
				++dataIter;
			}
			return returnResult;
		}

		template<typename TypeInit>
		Bool8 LoadJson(JsonData &jArray, TypeInit& initData)
		{
			Bool8 returnResult = false;
			dataList.resize(jArray.size());
			auto dataIter = dataList.begin();

			for (auto& element : jArray)
			{
				dataIter->reset(new TypeData(initData));
				returnResult = (*dataIter)->LoadJson(element);
				if (!returnResult)
				{
					return returnResult;
				}
				dataMap[(*dataIter)->GetName()] = (*dataIter);
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

		WeakPtr<TypeData> &GetDataFromName(String keyID)
		{
			return dataMap.at(keyID);
		}

		WeakPtr<TypeData> &GetDataFromName(AString keyID)
		{
			return dataMap.at(StringConv(keyID));
		}
	protected:
		Vector<SharedPtr<TypeData>> dataList;
		Map<String, WeakPtr<TypeData>> dataMap;
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
	.
	*/

}
