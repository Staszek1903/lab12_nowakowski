#ifndef CSORTTABLICA_H
#define CSORTTABLICA_H

#include "ctablica.h"
#include "menu.h"
#include "input.h"
#include "shufflinggenerator.h"
#include "file.h"

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
    void fill_tab_random(int count);
    void fill_tab_ordered(int count);
    void fill_tab_reversed(int count);
    void fill_tab_nearly_ordered(int count);

    void bubble_sort();
    void quick_sort_lomuto();
    void quick_sort_hoare();
    void heap_sort();

    void show_tab_content();
    void close_menu();

    void create_benchmark_file();

private:

    void benchark_with_filling(void (CSortTablica::*fill)(int count), pat::File & file, std::string fill_metode);
    
};

#endif // CSORTTABLICA_H
