#ifndef ANSI_H
#define ANSI_H

#include <iostream>
#include <iomanip>

namespace ansi {
    struct _EraseInLine { char _mode; };
    _EraseInLine erase_in_line(int mode);
    std::basic_ostream<char>& operator<<(std::basic_ostream<char>&, _EraseInLine);

    struct _ForegroundColorRGB { int _r; int _g; int _b; };
    _ForegroundColorRGB foreground_color(int r, int g, int b);
    std::basic_ostream<char>& operator<<(std::basic_ostream<char>&, _ForegroundColorRGB);

    struct _BackgroundColorRGB { int _r; int _g; int _b; };
    _BackgroundColorRGB background_color(int r, int g, int b);
    std::basic_ostream<char>& operator<<(std::basic_ostream<char>&, _BackgroundColorRGB);
} // namespace ansi

#endif