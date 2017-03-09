


#include "Giraffe.h"




int DLL_Module WorkMain(Giraffe::AString jsonString)
{


	Giraffe::GiraffeMain gMain;

	gMain.

	return 1;

	return 0;
}


namespace Giraffe
{
	GiraffeMain::GiraffeMain()
	{

	}
	GiraffeMain::~GiraffeMain()
	{

	}

	bool GiraffeMain::LoadJson(JsonData &jsonData)
	{
		auto jData = jsonData["Giraffe"];
		name = jData["Name"].get<AString>();
	}





}