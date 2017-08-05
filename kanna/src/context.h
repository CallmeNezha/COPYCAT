#include "kanna/kanna.h"

namespace KANNA
{
    struct Context
    {
        Context();
        ~Context();

        KANNA_API_FUNC(uint32_t frame(bool _capture = false));
    };



}