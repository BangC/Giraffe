

#pragma once

#define GOOGLE_GLOG_DLL_DECL
#include "../../../3rdParty/glog/src/windows/glog/logging.h"

namespace Giraffe
{
	class LogInit
	{
	public:
		LogInit();
		virtual ~LogInit();
	};


}