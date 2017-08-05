#include "kanna_private.h"
#include <kobayaxi/kobayaxi.h>
#include <stdint.h>

namespace KANNA
{
#define KANNA_MAIN_THREAD_MAGIC UINT32_C(0x78666762)

#if KANNA_CONFIG_MULTITHREADED
#	define KANNA_CHECK_MAIN_THREAD() \
				KOBAYAXI_CHECK(NULL != s_ctx, "Library is not initialized yet.") \
				KOBAYAXI_CHECK(KANNA_MAIN_THREAD_MAGIC == s_threadIndex, "Must be called from main thread.")
#	define KANNA_CHECK_RENDER_THREAD() \
				KOBAYAXI_CHECK(KOBAYAXI_MAIN_THREAD_MAGIC != s_threadIndex, "Must be called from render thread.")
#else
#	define KANNA_CHECK_MAIN_THREAD()
#	define KANNA_CHECK_RENDER_THREAD()
#endif // !KANNA_CONFIG_MULTITHREADRED


	static Context* s_ctx = NULL;
	static KOBAYAXI_THREAD_LOCAL uint32_t s_threadIndex(0);

	uint32_t frame(bool _capture)
	{
		return 1;
	}


}