#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include <cstdlib>

template <typename Owner>

/**
 * @brief The Menu class
 *  Klasa zawierajaca menu konsolowe
 *  elementy tego menu i odpowiadające im wskazniki do funkcji
 */
class Menu
{
    std::vector <std::string> items;
    std::vector <void (Owner::*)()> callbacks;
    Owner &owner;
public:
    /**
     * @brief Menu
     * @param owner - Klasa zawierająca funkcje wywolywane przez menu
     */
    Menu(Owner & owner)
        :owner(owner){}


    /**
     * @brief add_item dodaje elementy do menu
     * @param item - nazwa elementu
     * @param callback - funkcja wywolywana przez element
     */
    void add_item(std::string item, void (Owner::*callback)()){
        items.push_back(item);
        callbacks.push_back(callback);
    }

    /**
     * @brief execute wyswietla menu i oczekuje az element zostanie wybrany
     *      Nastepnie wywyolu odpowiadającą mu funkcje
     */
    void execute(){
        while(true){
            int input = -1;
            system("cls");
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
