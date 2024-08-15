#include "Hexagram.h"
#include <iostream>

int main()
{
    for (auto &&[name, type] : gramMap)
    {
        std::cout << name << " " << type << '\n'; 
        
    }
    


    return 0;
}