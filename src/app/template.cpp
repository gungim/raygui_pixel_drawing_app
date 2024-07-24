#include "template.hpp"
#include <vector>
namespace app {
    Templates::Templates() {
        this->tpls = {
            (Template){{0., 0.}, "Custom"},
            (Template){{16., 16.}, "16x16"},
            (Template){{32, 32}, "32x32"},
            (Template){{64, 64}, "64x64"},
            (Template){{128, 128}, "128x128"},
            // Nintendo
            (Template){{160, 144}, "GB"},
            (Template){{240, 160}, "GBA"},
            (Template){{256, 224}, "NES (NTSC)"},
            (Template){{256, 240}, "NES (PAL)"},
            (Template){{512, 448}, "SNES (NTSC)"},
            (Template){{512, 480}, "SNES (PAL)"},
            (Template){{646, 486}, "N64 (NTSC)"},
            (Template){{786, 576}, "N64 (PAL)"},
            // Sega
            (Template){{256, 192}, "SMS (NTSC)"},
            (Template){{256, 224}, "SMS (PAL)"},
            (Template){{160, 144}, "GG"},
            (Template){{320, 224}, "MD (NTSC)"},
            (Template){{320, 240}, "MD (PAL)"},
            // NEC
            (Template){{256, 239}, "PC Engine"},
            // DOS
            (Template){{320, 200}, "DOS EGA"},
            (Template){{320, 200}, "DOS VGA"},
            (Template){{620, 480}, "DOS SVGA"},
            (Template){{640, 200}, "DOS CGA (2-Colour)"},
            (Template){{320, 200}, "DOS CGA (4-Colour)"},
            (Template){{160, 240}, "DOS CGA (Composite)"},
            (Template){{160, 240}, "Tandy"},
            // Commodore
            (Template){{320, 200}, "Amiga OCS LowRes (NTSC)"},
            (Template){{320, 256}, "Amiga OCS LowRes (PAL)"},
            (Template){{640, 200}, "Amiga OCS HiRes  (NTSC)"},
            (Template){{640, 256}, "Amiga OCS HiRes  (PAL)"},
            (Template){{1280, 200}, "Amiga ECS Super-HiRes  (NTSC)"},
            (Template){{1280, 256}, "Amiga ECS SuperHiRes  (PAL)"},
            (Template){{640, 480}, "Amiga ECS Multiscan"},
            (Template){{320, 200}, "C64"},
            // Sinclair
            (Template){{256, 192}, "ZX Spectrum"},
        };
        this->tplsStr =
            "Custom;16x16;32x32;64x64;128x128;GB;GBA;NES("
            "NTSC);NES(PAL);SNES(NTSC);SNES(PAL);N64(NTSC);"
            "N64(PAL);SMS(NTSC);SMS(PAL);GG;MD(NTSC);MD("
            "PAL);PCEngine;DOSEGA;DOSVGA;DOSSVGA;DOSCGA(2-"
            "Colour);DOSCGA(4-Colour);DOSCGA(Composite);Tandy;"
            "AmigaOCSLowRes(NTSC);AmigaOCSLowRes(PAL);AmigaOCSHiRes("
            "NTSC);AmigaOCSHiRes(PAL);AmigaECSSuper-HiRes(NTSC);"
            "AmigaECSSuperHiRes(PAL);AmigaECSMultiscan;C64;"
            "ZXSpectrum;";
    }
    Templates::~Templates() {
        this->tpls.clear();
        this->tplsStr = nullptr;
    }
    std::vector<Template> Templates::getList() { return this->tpls; }
} // namespace app
