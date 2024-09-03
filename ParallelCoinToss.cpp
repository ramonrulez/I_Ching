#pragma once

#include "Random.h"
#include <iostream>

void parallelCoinToss()
{
    // Define a C-style array to save the coin toss results
    int tosses[6][3]{};
    
    // 6 tosses of 3 coins to make a Hexagram
    // The array is populated from the top to the bottom
    // bottom Gram to the top Gram
    for (size_t j = 0; j < 6; j++)
    {
        // 3 partallel coin tosses for 1 gram
        #pragma omp parallel
        for (size_t i = 0; i < 3; i++)
            tosses[j][i] = Random::get(0,1);
    }

    // TEST 
    for (size_t j = 0; j < 6; j++)
    {
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << tosses[j][i];
        }

        std::cout << '\n';
    }
}