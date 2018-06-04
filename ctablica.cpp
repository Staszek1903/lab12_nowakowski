#include "ctablica.h"

CTablica::CTablica()
{

}

void CTablica::foo()
{
    std::cout<<tab.size()<<std::endl;
    tab.push_back(11);
    std::cout<<tab.size()<<std::endl;
    std::cout<<tab[0]<<std::endl;
    tab.clear();
    std::cout<<tab.size()<<std::endl;
}
