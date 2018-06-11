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

void CSortTablica::fill_tab_ordered(int count)
{
    _tab.tab.resize(count);
    for(int i=0; i<count; ++i)
        _tab.tab[i] = i;
}

void CSortTablica::fill_tab_reversed(int count)
{
    _tab.tab.resize(count);
    for(int i=0; i<count; ++i)
        _tab.tab[i] = count - i;
}

void CSortTablica::fill_tab_nearly_ordered(int count)
{
    fill_tab_ordered(count);
    ShufflingGenerator generator(20,1000);

    for(int i=0; i<count; i+=10)
        _tab.tab[i] = generator.getRandom();
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
    auto result = _tab.quick_sort_hoare(0, _tab.tab.size()-1);
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

    benchark_with_filling(&CSortTablica::fill_tab_random, file, "random_fill");
    benchark_with_filling(&CSortTablica::fill_tab_ordered, file, "ordered_fill");
    benchark_with_filling(&CSortTablica::fill_tab_reversed, file, "reversed_fill");
    benchark_with_filling(&CSortTablica::fill_tab_nearly_ordered, file, "nearly_ordered");

    file.close();
}

void CSortTablica::benchark_with_filling(void (CSortTablica::*fill)(int count), pat::File &file, std::string fill_metode)
{
    auto& filestr = file.getFstream();

    std::cout<<"Metoda: "<<fill_metode<<std::endl;

    show_tab_content();

    std::cout<<"BUBBLE SORT"<<std::endl;
    (this->*fill)(100);
    auto result = _tab.bubble_sort();
    (this->*fill)(1000);
    auto result2 = _tab.bubble_sort();
    filestr<<"bubble sort: 100 "<<fill_metode<<" "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"bubble sort: 1000 "<<fill_metode<<" "<<result2.first<<" "<<result2.second<<std::endl;
    filestr<<"bubble sort: 1000 TOO LARGE "<<std::endl;

    std::cout<<"LOMUTO SORT"<<std::endl;
    (this->*fill)(100);
    result = _tab.quick_sort_lomuto(0,99);
    (this->*fill)(1000);
    result2 = _tab.quick_sort_lomuto(0,999);
    (this->*fill)(1000000);
    auto result3 = _tab.quick_sort_lomuto(0,999999);
    filestr<<"lomuto sort: 100 "<<fill_metode<<" "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"lomuto sort: 1000 "<<fill_metode<<" "<<result2.first<<" "<<result2.second<<std::endl;
    filestr<<"lomuto sort: 1000000 "<<fill_metode<<" "<<result3.first<<" "<<result3.second<<std::endl;

    std::cout<<"HOARE SORT"<<std::endl;
    (this->*fill)(100);
    result = _tab.quick_sort_hoare(0,99);
    (this->*fill)(1000);
    result2 = _tab.quick_sort_hoare(0,999);
    (this->*fill)(1000000);
    result3 = _tab.quick_sort_hoare(0,999999);
    filestr<<"hoare sort: 100 "<<fill_metode<<" "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"hoare sort: 1000 "<<fill_metode<<" "<<result2.first<<" "<<result2.second<<std::endl;
    filestr<<"hoare sort: 1000000 "<<fill_metode<<" "<<result3.first<<" "<<result3.second<<std::endl;

    std::cout<<"HEAP SORT"<<std::endl;
    (this->*fill)(100);
    result = _tab.heap_sort();
    (this->*fill)(1000);
    result2 = _tab.heap_sort();
    (this->*fill)(1000000);
    result3 = _tab.heap_sort();
    filestr<<"heap sort: 100 "<<fill_metode<<" "<<result.first<<" "<<result.second<<std::endl;
    filestr<<"heap sort: 1000 "<<fill_metode<<" "<<result2.first<<" "<<result2.second<<std::endl;
    filestr<<"heap sort: 1000000 "<<fill_metode<<" "<<result3.first<<" "<<result3.second<<std::endl;


}

void CSortTablica::close_menu()
{
    _menu_open = false;
}

