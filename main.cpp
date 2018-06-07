#include <iostream>
#include "csorttablica.h"
using namespace std;

int main()
{
    try{
        CSortTablica tab2;
        tab2.interface();
    }
    catch(std::exception & error){
        std::cout<<"ERROR: " <<error.what()<<std::endl;
        return 0;
    }


    return 0;
}
