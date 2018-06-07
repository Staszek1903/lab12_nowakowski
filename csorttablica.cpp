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
    _menu.add_item("generate sorting benchmark", &CSortTablica::create_benchmark_file);
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
    Input size_input(0,INT_MAX);
    Input elems_input;

    int count =0;
    int temp = 0;
    std::cout<<"manual fill"<<std::endl<<"elements count: ";
    count = size_input();

    _tab.tab.resize(count);
    for(int i=0; i<count; ++i){
        std::cout<<"elem"<<i<<": ";
        temp = elems_input();
        _tab.tab[i] = temp;
    }
}

void CSortTablica::fill_tab_random()
{
    Input size_input(0,INT_MAX);
    ShufflingGenerator generator(20,1000);

    int count =0;
    std::cout<<"random fill"<<std::endl<<"elements count: ";
    count = size_input();
    _tab.tab.resize(count);

    for(int i=0; i<count; ++i){
        _tab.tab[i] = generator.getRandom();
    }
}

void CSortTablica::fill_tab_random(int count)
{
    ShufflingGenerator generator(20,1000);
    _tab.tab.resize(count);

    for(int i=0; i<count; ++i){
        _tab.tab[i] = generator.getRandom();
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

void CSortTablica::create_benchmark_file()
{
    std::string dir;
    std::cout<<"file name: ";
    std::cin>>dir;

    pat::File file;
    file.create(dir);
    auto& filestr = file.getFstream();

    fill_tab_random(100);
    auto result = _tab.bubble_sort();
    fill_tab_random(1000);
    auto result2 = _tab.bubble_sort();
    filestr<<"bubble sort: 100 losowe elementy "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"bubble sort: 1000 losowe elementy "<<result2.first<<" "<<result2.second<<std::endl;

    fill_tab_random(100);
    result = _tab.quick_sort_lomuto(0,99);
    fill_tab_random(1000);
    result2 = _tab.quick_sort_lomuto(0,999);
    fill_tab_random(1000000);
    auto result3 = _tab.quick_sort_lomuto(0,999999);
    filestr<<"lomuto sort: 100 losowe elementy "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"lomuto sort: 1000 losowe elementy "<<result2.first<<" "<<result2.second<<std::endl;
    filestr<<"lomuto sort: 1000000 losowe elementy "<<result3.first<<" "<<result3.second<<std::endl;

    fill_tab_random(100);
    result = _tab.quick_sort_hoare();
    fill_tab_random(1000);
    result2 = _tab.quick_sort_hoare();
    fill_tab_random(1000000);
    result3 = _tab.quick_sort_hoare();
    filestr<<"hoare sort: 100 losowe elementy "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"hoare sort: 1000 losowe elementy "<<result2.first<<" "<<result2.second<<std::endl;
    filestr<<"hoare sort: 1000000 losowe elementy "<<result3.first<<" "<<result3.second<<std::endl;

    fill_tab_random(100);
    result = _tab.heap_sort();
    fill_tab_random(1000);
    result2 = _tab.heap_sort();
    fill_tab_random(1000000);
    result3 = _tab.heap_sort();
    filestr<<"heap sort: 100 losowe elementy "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"heap sort: 1000 losowe elementy "<<result2.first<<" "<<result2.second<<std::endl;
    filestr<<"heap sort: 1000000 losowe elementy "<<result3.first<<" "<<result3.second<<std::endl;

    file.close();
}

void CSortTablica::close_menu()
{
    _menu_open = false;
}

