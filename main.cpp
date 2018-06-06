#include <iostream>
#include "csorttablica.h"
using namespace std;

int main()
{

    CSortTablica tab;
    tab.interface();

    CTablica tab;
    tab.tab = {2,3,1};
    auto bubbleResult=tab.bubble_sort(); //auto: bubbleResult otrzymuje typ, ktory ma metoda po prawej stronie
    cout<<bubbleResult.first<<" "<<bubbleResult.second<<endl;
    return 0;
}
