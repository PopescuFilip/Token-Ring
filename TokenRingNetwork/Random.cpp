#include "Random.h"

int GetRandom(int lowerLimit, int upperLimit)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(lowerLimit, upperLimit);
    return dis(gen);
}