#ifndef SHUFFLINGGENERATOR_H
#define SHUFFLINGGENERATOR_H

#include "additivgenerator.h"

/**
 * @brief The ShufflingGenerator class
 *      Genrator liczb pseudolosowych metodą tasowania
 */
class ShufflingGenerator
{
    std::vector <int> shuffling_array;
    int modullo;
    int Y;

    AdditivGenerator generator;
public:
    /**
     * @brief ShufflingGenerator
     * @param shuffling_size - wielkosc tablicy tasowania
     * @param modullo - modullo losowania
     */
    ShufflingGenerator(int shuffling_size, int modullo);

    /**
     * @brief getRandom zwraca liczbe pseudolosowa
     * @return  liczba
     */
    int getRandom();

    /**
     * @brief printTable wyswietla elementy tablicy tasowania
     */
    void printTable();
};

#endif // SHUFFLINGGENERATOR_H
