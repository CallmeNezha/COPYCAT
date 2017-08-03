#ifndef KANNA_UTILITIES_H_HEADER_GUARD
#define KANNA_UTILITIES_H_HEADER_GUARD

#include <kanna/kanna.h>

struct Args
{
	Args(int _argc, char** _argv);

	KANNA::RendererType::Enum m_type;
	uint16_t			      m_pciId;
};

#endif // !KANNA_UTILITIES_H_HEADER_GUARD