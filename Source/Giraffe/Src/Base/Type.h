

#pragma once


#include <vector>
#include <memory>
#include <string>

#include "../../../3rdParty/json/src/json.hpp"
namespace Giraffe
{


	typedef int Int32;
	typedef long long Int64;
	typedef float Float32;
	typedef double Float64;

	typedef bool Bool8;

	template<typename DataType>
	using Vector = std::vector<DataType>;

	template<typename DataType>
	using SharedPtr = std::shared_ptr<DataType>;
	template<typename DataType>
	using WeakPtr = std::weak_ptr<DataType>;

	typedef std::wstring String;
	typedef std::string AString;

	using JsonData = nlohmann::json;

	class BaseObject
	{
	public:
		BaseObject()
		{

		}
		virtual ~BaseObject()
		{

		}
	protected:
		String name;
		String displayName;
		//String uniqueKey;
	};

	class JsonLoader
	{
	public:
		JsonLoader()
		{

		}
		virtual ~JsonLoader()
		{

		}

		virtual bool LoadJson(AString &jsonString)
		{
			auto jData = JsonData::parse(jsonString);
			return LoadJson(jData);
		}
		virtual bool LoadJson(JsonData &jsonData) = 0;
	protected:
	};

	/*
	부족한것 만들어야할것

	. 버전
	. 싱글턴
	*/

}
