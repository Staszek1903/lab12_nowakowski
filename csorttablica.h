#ifndef CSORTTABLICA_H
#define CSORTTABLICA_H

#include "ctablica.h"
#include "menu.h"
#include <iostream>

class CSortTablica
{
    CTablica _tab;
    Menu <CSortTablica> _menu;

public:
    CSortTablica();

    void interface();

private:
    void foo1();
    void foo2();
    void foo3();
};

#endif // CSORTTABLICA_H
