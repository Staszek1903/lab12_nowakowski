#ifndef ADDITIVGENERATOR_H
#define ADDITIVGENERATOR_H

#include <utility>
#include <vector>
#include <iostream>
#include <time.h>
#include "lineargenerator.h"

/**
 * @brief The AdditivGenerator class
 *      Generator liczb pseudolosowych metodą addytywną
 */
class AdditivGenerator
{
    int modulo;
    std::vector <int> array;
    std::pair <int, int>  base_pair;
public:

    /**
     * @brief AdditivGenerator
     *
     * @param size - rozmiaz tablicy tosowania
     * @param mod  - modullo generatora
     */
    AdditivGenerator(int size, int mod);

    /**
     * @brief getRandom zwraca liczbe pseudolosową
     * @return liczba pseudolosowa
     */
    int getRandom();

    /**
     * @brief printTable wyswietla tablice
     */
    void printTable();
};

static std::pair <int, int> pairs [] =
{
    {1, 2}, {1,15}, { 5,23}, { 7,31}, { 5,47}, {21,52}, {18,65}, {28,73}, { 2,93},
    {1, 3}, {4,15}, { 9,23}, {13,31}, {14,47}, {24,55}, {32,65}, {31,73}, {21,94},
    {1, 4}, {7,15}, { 3,25}, {13,33}, {20,47}, { 7,57}, { 9,68}, { 9,79}, {11,95},
    {2, 5}, {3,17}, { 7,25}, { 2,35}, {21,47}, {22,57}, {33,68}, {19,79}, {17,95},
    {1, 6}, {5,17}, { 3,28}, {11,36}, { 9,49}, {19,58}, { 6,71}, { 4,81}, { 6,97},
    {1, 7}, {6,17}, { 9,28}, { 4,39}, {12,49}, { 1,60}, { 9,71}, {16,81}, {12,97},
    {3, 7}, {7,18}, {13,28}, { 8,39}, {15,49}, {11,60}, {18,71}, {35,81}, {33,97},
    {4, 9}, {3,20}, { 2,29}, {14,39}, {22,49}, { 1,63}, {20,71}, {13,84}, {34,97},
    {3,10}, {2,21}, { 3,31}, { 3,41}, { 3,52}, { 5,63}, {35,71}, {13,87}, {11,98},
    {2,11}, {1,22}, { 6,31}, {20,41}, {19,52}, {31,63}, {25,73}, {38,89}, {27,98},
};

#endif // ADDITIVGENERATOR_H
