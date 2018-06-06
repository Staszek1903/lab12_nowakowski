#include "csorttablica.h"

CSortTablica::CSortTablica()
    :_menu(*this), _menu_open(true)
{
    _menu.add_item("manual fill",&CSortTablica::fill_tab_manual);
    _menu.add_item("random fill",&CSortTablica::fill_tab_random);
    _menu.add_item("bubble sort",&CSortTablica::bubble_sort);
    _menu.add_item("quick sort hoare",&CSortTablica::quick_sort_hoare);
    _menu.add_item("quick sort lomuto",&CSortTablica::quick_sort_lomuto);
    _menu.add_item("heap_sort",&CSortTablica::heap_sort);
    _menu.add_item("tab content", &CSortTablica::show_tab_content);
    _menu.add_item("exit", &CSortTablica::close_menu);
}

void CSortTablica::interface()
{
    while (true) {
        _menu.execute();

        if(!_menu_open)
            break;

        char a;
        std::cout<<"DONE, enter any char"<<std::endl;
        std::cin>>a;
    }
}

void CSortTablica::fill_tab_manual()
{
    int count =0;
    int temp = 0;
    std::cout<<"manual fill"<<std::endl<<"elements count: ";
    std::cin>>count;

    _tab.tab.resize(count);
    for(int i=0; i<count; ++i){
        std::cout<<"elem"<<i<<": ";
        std::cin>>temp;
        _tab.tab[i] = temp;
    }
}

void CSortTablica::fill_tab_random()
{
    int count =0;
    int temp = 0;
    std::cout<<"random fill"<<std::endl<<"elements count: ";
    std::cin>>count;
    _tab.tab.resize(count);

    for(int i=0; i<count; ++i){
        temp = count - i;
        _tab.tab[i] = temp;
    }
}

void CSortTablica::bubble_sort()
{
    auto result = _tab.bubble_sort();
    std::cout<<result.first<<" "<<result.second<<std::endl;
}

void CSortTablica::quick_sort_lomuto()
{
    auto result = _tab.quick_sort_lomuto(0, _tab.tab.size()-1);
    std::cout<<result.first<<" "<<result.second<<std::endl;
}

void CSortTablica::quick_sort_hoare()
{
    auto result = _tab.quick_sort_hoare();
    std::cout<<result.first<<" "<<result.second<<std::endl;
}

void CSortTablica::heap_sort()
{
    auto result = _tab.heap_sort();
    std::cout<<result.first<<" "<<result.second<<std::endl;
}

void CSortTablica::show_tab_content()
{
    std::cout<<"tab size: "<<_tab.tab.size()<<std::endl<<"elements: ";
    for(auto a: _tab.tab){
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
}

void CSortTablica::close_menu()
{
    _menu_open = false;
}

