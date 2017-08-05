#ifndef KANNA_H_HEADER_GUARD
#define KANNA_H_HEADER_GUARD

//TODO: use CMake to configure these
#define KANNA_CONFIG_MULTITHREADED      1

/// Include required headers 
#include <stdarg.h> // va_list
#include <stdint.h> // uint32_t
#include <stdlib.h> // NULL

#include "defines.h"
#include "macros.h"

namespace KANNA
{
    /// Renderer backend type enum
    struct RendererType
    {
        enum Enum
        {
            Noop,         //!< No rendering
            Direct3D12,   //!< Direct3D 12.0
            OpenGL,       //!< OpenGL 2.1+
            Vulkan,       //!< Vulkan

            Count
        };
    };


    ///
    /// Advance to next frame. When using multithreaded renderer, this call
    /// just swaps internal buffers, kicks render thread, and returns.
    /// @param[in] _capture Capture frame with graphics debugger.
    /// @returns Current frame number. This might be used in conjunction with
    ///     double/multi buffering data outside the library and passing it to
    ///     library via `KANNA::makeRef` calls.
    ///
    uint32_t frame(bool _capture = false);


    //bool init(
    //    RendererType::Enum _type = RendererType::Count
    //    , uint16_t _vendorId = KANNA_PCI_ID_NONE
    //    , uint16_t _deviceId = 0
    //    , CallbackI* _callback = NULL
    //    , KOBAYAXI::
    //);

}

#endif // !KANNA_H_HEADER_GUARD