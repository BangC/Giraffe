
#include "Version.h"



namespace Giraffe
{

	VersionData::VersionData(Int32 Major, Int32 Minor, Int32 Revision)
		: major(Major)
		, minor(Minor)
		, revision(Revision)
	{
	}
	VersionData::~VersionData()
	{

	}

	bool VersionData::operator == (const VersionData &rRef) const
	{
		return (major == rRef.major)
			&& (minor == rRef.minor)
			&& (revision == rRef.revision);
	}

	bool VersionData::operator != (const VersionData &rRef) const
	{
		return !((*this) == rRef);
	}


	Bool8 VersionData::LoadJson(JsonData &jsonData)
	{
		if (jsonData.empty())
		{
			LOG(ERROR) << "No Data";
			return false;
		}
		major = jsonData["Major"];
		minor = jsonData["Minor"];
		revision = jsonData["Revision"];

		VersionData codeVersionCheck(VersionMajor, VersionMinor, VersionRevision);
		Bool8 sameVersion = (codeVersionCheck == (*this));
		if (!sameVersion)
		{
			LOG(ERROR) << "Version Match Error";
			ShowDebug();
			LOG(ERROR) << "Version Need";
			codeVersionCheck.ShowDebug();
		}
			
		return sameVersion;
	}

	void VersionData::ShowDebug()
	{
		LOG(INFO) << "[VersionData] V." << major << "." << minor << "." << revision;
	}

}