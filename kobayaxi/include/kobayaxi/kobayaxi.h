#ifndef KOBAYAXI_H_HEADER_GUARD
#define KOBAYAXI_H_HEADER_GUARD



//TODO: use cmake to config platform
#define KOBAYAXI_PLATFORM_WIN	1
#define KOBAYAXI_PLATFORM_UNIX	0
#define KOBAYAXI_CONFIG_DEBUG   1

#include <windows.h>
#include "platform.h"
#include "macros.h"

///
#define KOBAYAXI_COUNTOF(_x) sizeof(KOBAYAXI::COUNTOF_REQUIRES_ARRAY_ARGUMENT(_x) )

namespace KOBAYAXI
{
	void trace(const char* _filePath, uint16_t _line, const char* _format, ...);

    // http://cnicholson.net/2011/01/stupid-c-tricks-a-better-sizeof_array/
    template<typename T, size_t N>
    char(&COUNTOF_REQUIRES_ARRAY_ARGUMENT(const T(&)[N]))[N];
}

#endif