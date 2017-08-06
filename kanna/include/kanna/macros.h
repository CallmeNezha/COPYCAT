#include <kobayaxi/kobayaxi.h>

#if KANNA_CONFIG_DEBUG
#   define KANNA_API_FUNC(_func) KOBAYAXI_NO_INLINE _func
#else
#   define KANNA_API_FUNC(_func) _func
#endif // !KANNA_CONFIG_DEBUG



/// KOBAYAXI override

#if KANNA_CONFIG_DEBUG
#	define KANNA_CHECK _KANNA_CHECK
#else
#endif // !KANNA_CONFIG_DEBUG
