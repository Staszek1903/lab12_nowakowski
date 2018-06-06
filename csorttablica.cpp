#include "csorttablica.h"

CSortTablica::CSortTablica()
    :_menu(*this)
{
    _menu.add_item("menu_foo1",&CSortTablica::foo1);
    _menu.add_item("menu_foo2",&CSortTablica::foo2);
    _menu.add_item("menu_foo2",&CSortTablica::foo3);
}

void CSortTablica::interface()
{
    while(true)
        _menu.execute();
}

void CSortTablica::foo1()
{
    std::cout<<"foo1"<<std::endl;
}

void CSortTablica::foo2()
{
    std::cout<<"foo2"<<std::endl;
}

void CSortTablica::foo3()
{
    std::cout<<"foo3"<<std::endl;
}
