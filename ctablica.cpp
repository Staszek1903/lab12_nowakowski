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
        return std::make_pair<int,int> (int (ComparisonCounter), int(SwapCounter));

    //std::pair <int, int> p;
    //return p;
    //int x,y;
    //return std::make_pair<int,int>(x,y);
}

std::pair<int, int> CTablica::quick_sort_lomuto(int indexA, int indexB)
{
    std::cout<<indexA<<" "<<indexB<<std::endl;


    int pivotValue, b;
    int SwapCounter=0;
    int ComparisonCounter=0;
    pivotValue = tab[indexA];
    std::swap (tab[indexA], tab[tab.size()-1]);
    b = indexA;

    for(int a =indexA; a <= tab.size()-1; a++) {
        if(tab[a] <= pivotValue)
            {
            b++;

            std::swap (tab[a], tab[b]);
            }
    }
    std::swap(tab[b +1], tab[tab.size()-1]);

    if(b-1>indexA)
    quick_sort_lomuto(indexA,b-1 );
    if(b-1<indexB)
    quick_sort_lomuto(b+1, indexB);
    return std::make_pair<int,int> (0,0);
}

std::pair<int, int> CTablica::quick_sort_hoare()
{

}

std::pair<int, int> CTablica::heap_sort()
{

}
