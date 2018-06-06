#ifndef CTABLICA_H
#define CTABLICA_H

#include <iostream>
#include <vector>
#include <utility>

class CTablica
{
public:
    CTablica();

    std::vector <int> tab;

    //returns first- comparison count; second- swap count
    std::pair <int, int> bubble_sort();
    std::pair <int, int> quick_sort_lomuto();
    std::pair <int, int> quick_sort_hoare();
    std::pair <int, int> heap_sort();


};

#endif // CTABLICA_H
