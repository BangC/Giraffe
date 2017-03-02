

#pragma once


#include <vector>
#include <memory>
#include <string>

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

	typedef std::wstring String;

	class Object
	{
	public:
	};
}
