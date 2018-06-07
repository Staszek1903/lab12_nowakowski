#include "additivgenerator.h"

AdditivGenerator::AdditivGenerator(int size, int mod)
    :modulo(mod), array(size)
{
    LinearGenerator generator(mod, time(NULL) % mod);

    for(int i =89; i>=0; --i)
        if(pairs[i].second < size){
            base_pair = pairs[i];
            break;
        }

    for(int i=0; i<size; ++i)
        array.at(i) = generator.getRandom();
}

int AdditivGenerator::getRandom()
{
    int result = array[base_pair.second] = (array[base_pair.first] + array[base_pair.second]) % modulo;
    base_pair.first = (base_pair.first == 0)? (array.size()-1) : (base_pair.first-1);
    base_pair.second = (base_pair.second == 0)? (array.size()-1) : (base_pair.second-1);
    return result;
}

void AdditivGenerator::printTable()
{
    for(int a: array)
        std::cout<<a<<" ";
    std::cout<<std::endl;
}
