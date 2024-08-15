#include "Hexagram.h"
#include <iostream>

int main() {
    for (auto &&[name, type] : gramMap) {
        std::cout << name << " " << type << '\n';
    }
    
    UpperTrigram up{};
    LowerTrigram down{};

    up.m_upGram_1 = "dasdas";
    up.m_upGram_2 = "dsadas";
    up.m_upGram_3 = ":dsadas";

    down.m_logram_1 = "dsadas";
    down.m_logram_2 = "dsada";
    down.m_logram_3 = "dsa";

    Hexagram a{up, down};
    return 0;
}