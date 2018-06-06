#include <iostream>
#include "ctablica.h"
using namespace std;

int main()
{
    CTablica tab;
    tab.tab = {1, 2,3,};
    auto bubbleResult=tab.bubble_sort(); //auto: bubbleResult otrzymuje typ, ktory ma metoda po prawej stronie
    cout<<bubbleResult.first<<" "<<bubbleResult.second<<endl;


    return 0;
}
