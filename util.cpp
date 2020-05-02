//
// Created by nick on 5/2/20.
//
#include "util.hpp"
#define BOLD(x) "\x1B[1m" x RST

void printInColor(Color::Code c, std::string s, bool bold) {
    Color::Modifier mainColor(c);

    Color::Modifier def(Color::FG_DEFAULT);
    if(bold) {
        Color::Modifier bold(Color::BOLD);
        Color::Modifier noBold(Color::NO_BOLD);
        std::cout << bold << mainColor << s << def << noBold  << std::endl;
    } else {
        std::cout << mainColor << s << def << std::endl;
    }
}