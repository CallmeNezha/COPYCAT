#ifndef KANNA_DEFINES_H_HEADER_GUARD
#define KANNA_DEFINES_H_HEADER_GUARD



#define KANNA_PCI_ID_NONE                   UINT16_C(0x0000) //!< Autoselect adapter.
#define KANNA_PCI_ID_SOFTWARE_RASTERIZER    UINT16_C(0x0001) //!< Software rasterizer.
#define KANNA_PCI_ID_AMD                    UINT16_C(0x1002) //!< AMD adapter.
#define KANNA_PCI_ID_INTEL                  UINT16_C(0x8086) //!< Intel adapter.
#define KANNA_PCI_ID_NVIDIA                 UINT16_C(0x10de) //!< nVidia adapter.

#define KANNA_DEBUG_NONE                    UINT32_C(0x00000000) //!< No debug.
#define KANNA_DEBUG_WIREFRAME               UINT32_C(0x00000001) //!< Enable wireframe for all primitives.
#define KANNA_DEBUG_IFH                     UINT32_C(0x00000002) //!< Enable infinitely fast hardware test. No draw calls will be submitted to driver. It¡¯s useful when profiling to quickly assess bottleneck between CPU and GPU.
#define KANNA_DEBUG_STATS                   UINT32_C(0x00000004) //!< Enable statistics display.
#define KANNA_DEBUG_TEXT                    UINT32_C(0x00000008) //!< Enable debug text display.


#define KANNA_RESET_NONE                    UINT32_C(0x00000000) //!< No reset flags.
#define KANNA_RESET_VSYNC                   UINT32_C(0x00000001) //!< Enable V-Sync.
#define KANNA_RESET_MSAA_X2                 UINT32_C(0x00000010) //!< Enable 2x MSAA.
#define KANNA_RESET_MSAA_X4                 UINT32_C(0x00000020) //!< Enable 4x MSAA.
#define KANNA_RESET_MSAA_X8                 UINT32_C(0x00000030) //!< Enable 8x MSAA.
#define KANNA_RESET_MSAA_X16                UINT32_C(0x00000040) //!< Enable 16x MSAA.


#endif // !KANNA_DEFINES_H_HEADER_GUARD