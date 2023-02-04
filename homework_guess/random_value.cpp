#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomValue()
{
    std::srand((unsigned int)std::time(nullptr));
    return std::rand() % 100;
}