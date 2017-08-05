#define KOBAYAXI_CONFIG_DEBUG   true

#include <stdio.h>
#include "entry/entry.h"
#include <kanna/kanna.h>
#include <kanna_utils.h>



class A final : public entry::AppI
{
public:
    void init(int _argc, char** _argv) override 
    {
        Args args = Args(_argc, _argv);

        KOBAYAXI_TRACE("bs");

        m_width = 1280;
        m_height = 720;
        m_debug = KANNA_DEBUG_TEXT;
        m_reset = KANNA_RESET_VSYNC | KANNA_RESET_MSAA_X16;


    }
    int  shutdown() override { return 1; }
    bool update() override { return true; }


private:


    uint32_t m_width;
    uint32_t m_height;
    uint32_t m_debug;
    uint32_t m_reset;


};

ENTRY_IMPLEMENT_MAIN(A);



