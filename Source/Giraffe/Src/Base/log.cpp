
#include "log.h"



namespace Giraffe
{
	LogInit g_LogInit;

	LogInit::LogInit()
	{
		google::InitGoogleLogging("Giraffe_Test");
		google::SetLogDestination(google::GLOG_INFO, "./Test.");
		//google::SetLogFilenameExtension(".BC.log");
		google::LogToStderr();
	}
	LogInit::~LogInit()
	{

	}
}