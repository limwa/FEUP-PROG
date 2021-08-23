#include "ansi.h"

namespace ansi {

    _EraseInLine erase_in_line(int mode) {
        if (mode < 0 || mode > 2)
            throw "Mode must be 0, 1 or 2";

        return {
            char(mode + 48)
        };
    }

    std::basic_ostream<char>& operator<<(std::basic_ostream<char>& __os, _EraseInLine __f) {
        __os << "\x1B[" << __f._mode << 'K';
        return __os;
    }

    _ForegroundColorRGB foreground_color(int r, int g, int b) {
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            throw "RGB values must be between 0 and 255";

        return { r, g, b };
    }

    std::basic_ostream<char>& operator<<(std::basic_ostream<char>& __os, _ForegroundColorRGB __f) {
        __os << "\x1B[38;2;" << __f._r << ';' << __f._g << ';' << __f._b << 'm';
        return __os;
    }

    _BackgroundColorRGB background_color(int r, int g, int b) {
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            throw "RGB values must be between 0 and 255";

        return { r, g, b };
    }

    std::basic_ostream<char>& operator<<(std::basic_ostream<char>& __os, _BackgroundColorRGB __f) {
        __os << "\x1B[48;2;" << __f._r << ';' << __f._g << ';' << __f._b << 'm';
        return __os;
    }
} // namespace ansi