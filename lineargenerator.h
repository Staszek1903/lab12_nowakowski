#ifndef LINEARGENERATOR_H
#define LINEARGENERATOR_H

#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief The LinearGenerator class
 *  Generator liczb pseudorolowych metodą liniową
 */
class LinearGenerator
{
    int xmax;
    int modullo;
    int xn;
    int c;
    int a;
public:
    /**
     * @brief LinearGenerator
     * @param xmax maxymalna wartosc losowania
     * @param seed ziarno losowania
     */
    LinearGenerator(int xmax, int seed);

    /**
     * @brief getRandom
     * @return zwraca liczbe pseudolosowa
     */
    int getRandom();

private:
    int choose_c();
    int choose_a();
};

/**
 * @brief prime factors szuka czynnikow pierwszych liczby
 * @param number liczba do podzielenia
 * @return tablica liczb pierwszych
 */
std::vector <int> prime_factors(int number);

/**
 * @brief is_prime czy liczba jest pierwsza
 * @param number liczba
 * @return czy jest pierwsza
 */
bool is_prime(int number);

/**
 * @brief is_inside sprawdza czy liczba znajduje sie w tablicy
 * @param vector tablica
 * @param number liczba
 * @return czy sie znajduje
 */
bool is_inside(std::vector <int> vector, int number);

#endif // LINEARGENERATOR_H
