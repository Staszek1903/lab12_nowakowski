#include "shufflinggenerator.h"

ShufflingGenerator::ShufflingGenerator(int shuffling_size, int modullo)
    :shuffling_array(shuffling_size), modullo(modullo), generator(shuffling_size, modullo)
{
    for(int & a: shuffling_array)
        a = generator.getRandom();

    Y = generator.getRandom();
}

int ShufflingGenerator::getRandom()
{
    int j = (shuffling_array.size()*Y)/ modullo;
    int result = Y = shuffling_array.at(j);
    shuffling_array.at(j) = generator.getRandom();
    return result;
}

void ShufflingGenerator::printTable()
{
    for(int & b: shuffling_array)
        std::cout <<b<<" ";
    std::cout<<std::endl;
}
