#ifndef COLOR_H // include guard
#define COLOR_H

#include <ostream>

//const std::string red("\033[0;31m");
//const std::string green("\033[1;32m");
//const std::string yellow("\033[1;33m");
//const std::string cyan("\033[0;36m");
//const std::string magenta("\033[0;35m");
//const std::string reset("\033[0m");


namespace Color {
    enum Code {
        BOLD      = 1,
        NO_BOLD      = 2,
        FG_RED      = 31, //Foreground
        FG_GREEN    = 32,
        FG_YELLOW    = 33,
        FG_BLUE     = 34,
        FG_PURPLE     = 35,
        FG_CYAN     = 36, //More of a Teal
        FG_GRAY     = 37,
        FG_WHITE     = 38,
        FG_DEFAULT  = 39,
        BG_RED      = 41, //Background
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}


#endif