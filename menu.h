#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include <cstdlib>

template <typename Owner>
class Menu
{
    std::vector <std::string> items;
    std::vector <void (Owner::*)()> callbacks;
    Owner &owner;
public:

    Menu(Owner & owner)
        :owner(owner){}

    void add_item(std::string item, void (Owner::*callback)()){
        items.push_back(item);
        callbacks.push_back(callback);
    }

    void execute(){
        while(true){
            int input = -1;
            system("clear");
            print_items();
            std::cin>>input;

            if(input > callbacks.size())
                continue;

            void (Owner::*output)() = callbacks[input];
            (owner.*output)();
            return;
        }
    }

private:
    void print_items(){
        for(int i =0; i<items.size(); ++i)
            std::cout<<i<<"- "<<items[i]<<std::endl;
    }
};

#endif // MENU_H
