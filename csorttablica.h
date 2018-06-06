#ifndef CSORTTABLICA_H
#define CSORTTABLICA_H

#include "ctablica.h"
#include "menu.h"
#include <iostream>

class CSortTablica
{
    CTablica _tab;
    Menu <CSortTablica> _menu;
    bool _menu_open;

public:
    CSortTablica();

    void interface();

    void fill_tab_manual();
    void fill_tab_random();

    void bubble_sort();
    void quick_sort_lomuto();
    void quick_sort_hoare();
    void heap_sort();

    void show_tab_content();
    void close_menu();

private:
    
};

#endif // CSORTTABLICA_H
