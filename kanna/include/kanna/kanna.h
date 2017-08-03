#ifndef KANNA_H_HEADER_GUARD
#define KANNA_H_HEADER_GUARD

#include <stdarg.h> // va_list
#include <stdint.h> // uint32_t
#include <stdlib.h> // NULL

#include "defines.h"

namespace KANNA
{
	/// Renderer backend type enum
	struct RendererType
	{
		enum Enum
		{
			Noop,         //!< No rendering
			Direct3D12,   //!< Direct3D 12.0
			OpenGL,		  //!< OpenGL 2.1+
			Vulkan,       //!< Vulkan

			Count
		};
	};
}

#endif // !KANNA_H_HEADER_GUARD