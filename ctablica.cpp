#include "ctablica.h"

CTablica::CTablica()
{

}

std::pair<int, int> CTablica::bubble_sort()
{
    int SwapCounter=0;
    int ComparisonCounter=0;
    for(int i=0;i<tab.size();i++){
        for(int j=1;j<tab.size()-i;j++)
        {
            ComparisonCounter++;
            if(tab[j-1]>tab[j])
                {
                    std::swap(tab[j-1], tab[j]);
                    SwapCounter++;
                }
        }
    }
    return std::make_pair<int,int> (int(ComparisonCounter), int(SwapCounter));

    //std::pair <int, int> p;
    //return p;
    //int x,y;
    //return std::make_pair<int,int>(x,y);
}

std::pair<int, int> CTablica::quick_sort_lomuto(int indexA, int indexB)
{

    if(indexA>=indexB)return std::make_pair<int,int>(0,0);

    int pivotValue, b;
    int SwapCounter=2;
    int ComparisonCounter=0;
    pivotValue = tab[indexA];
    std::swap (tab[indexA], tab[indexB]);
    b = indexA;

    for(int a =indexA; a < indexB; a++) {
            ComparisonCounter++;
        if(tab[a] <= pivotValue)
            {
                std::swap (tab[a], tab[b]);
                SwapCounter++;
                b++;
            }
    }
    std::swap(tab[b], tab[indexB]);


    auto result1 = quick_sort_lomuto(indexA,b-1 );

    auto result2 = quick_sort_lomuto(b+1, indexB);
    ComparisonCounter += result1.first+result2.first;
    SwapCounter+=result1.second+result2.second;
    return std::make_pair<int,int> (int(ComparisonCounter), int(SwapCounter));
}

std::pair<int, int> CTablica::quick_sort_hoare()
{
    return std::make_pair<int,int> (0,0);
}

std::pair<int, int> CTablica::heap_sort()
{
    return std::make_pair<int,int> (0,0);
}
