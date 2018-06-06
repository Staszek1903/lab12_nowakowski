#include <iostream>
#include "csorttablica.h"
using namespace std;

int main()
{


    CTablica tab;
    int indexA, indexB;
    tab.tab = {1, 2,3,};
    auto bubbleResult=tab.bubble_sort(); //auto: bubbleResult otrzymuje typ, ktory ma metoda po prawej stronie
    cout<<bubbleResult.first<<" "<<bubbleResult.second<<endl;
    indexA=0;
    indexB= tab.tab.size()-1;
    tab.quick_sort_lomuto(indexA, indexB);
    return 0;
}
