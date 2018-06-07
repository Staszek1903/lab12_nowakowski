#ifndef LINEARGENERATOR_H
#define LINEARGENERATOR_H

#include <iostream>
#include <vector>
#include <cmath>

class LinearGenerator
{
    int xmax;
    int modullo;
    int xn;
    int c;
    int a;
public:
    LinearGenerator(int xmax, int seed);
    int getRandom();

private:
    int choose_c();
    int choose_a();
};

std::vector <int> prime_factors(int number);
bool is_prime(int number);
bool is_inside(std::vector <int> vector, int number);

#endif // LINEARGENERATOR_H
