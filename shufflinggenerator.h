#ifndef SHUFFLINGGENERATOR_H
#define SHUFFLINGGENERATOR_H

#include "additivgenerator.h"

class ShufflingGenerator
{
    std::vector <int> shuffling_array;
    int modullo;
    int Y;

    AdditivGenerator generator;
public:
    ShufflingGenerator(int shuffling_size, int modullo);

    int getRandom();
    void printTable();
};

#endif // SHUFFLINGGENERATOR_H
