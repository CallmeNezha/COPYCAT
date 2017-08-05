#include "kanna_utils.h"

Args::Args(int _argc, char** _argv)
    : m_type(KANNA::RendererType::Count)
    , m_pciId(KANNA_PCI_ID_NONE)
{
    //TODO: finish KOBAYAXI CommandLine tool
    m_type = KANNA::RendererType::OpenGL;
    m_pciId = KANNA_PCI_ID_NVIDIA;
}

