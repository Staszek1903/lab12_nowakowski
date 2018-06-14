#ifndef CSORTTABLICA_H
#define CSORTTABLICA_H

#include "ctablica.h"
#include "menu.h"
#include "input.h"
#include "shufflinggenerator.h"
#include "file.h"

/**
 * @brief The CSortTablica class
 *      Klasa zamierająca interfejs obsugi sortowania tablicy
 */
class CSortTablica
{
    CTablica _tab;
    Menu <CSortTablica> _menu;
    bool _menu_open;

public:
    CSortTablica();

    /**
     * @brief interface wywoluje interface obslugi tablicy
     */
    void interface();

    /**
     * @brief fill_tab_manual wypelnianie tablicy z klawiatury
     */
    void fill_tab_manual();

    /**
     * @brief fill_tab_random wypenianie tablicy liczbami psudolosowymi
     */
    void fill_tab_random();

    /**
     * @brief fill_tab_random ditto
     * @param count - liczba elementów w tablicy
     */
    void fill_tab_random(int count);

    /**
     * @brief fill_tab_ordered wypalnia tablice liczbami uporzadkowanymi rosnaco
     * @param count - liczba elementow
     */
    void fill_tab_ordered(int count);

    /**
     * @brief fill_tab_reversed wypelnia tablice liczbami uporzadkowanymi malejaco
     * @param count - liczba elementow
     */
    void fill_tab_reversed(int count);

    /**
     * @brief fill_tab_nearly_ordered wypelnia tablice liczbami takimi ze 10% nie jest uporzadkowane
     * @param count - liczba elementow
     */
    void fill_tab_nearly_ordered(int count);

    /**
     * @brief bubble_sort sortuje tablice babelkowo
     */
    void bubble_sort();

    /**
     * @brief quick_sort_lomuto sortuje tablice szybkim sortowanie wersja lomuto
     */
    void quick_sort_lomuto();

    /**
     * @brief quick_sort_hoare sortuje tablice szybkim sortowanie wersja hoare
     */
    void quick_sort_hoare();

    /**
     * @brief heap_sort sortuje tablice przez kopcowanie
     */
    void heap_sort();

    /**
     * @brief show_tab_content wypisuje elementy tablicy i jej wielkosc na standartowe wyjscie
     */
    void show_tab_content();

    /**
     * @brief close_menu konczy egzekucje interface'u
     */
    void close_menu();

    /**
     * @brief create_benchmark_file tworzy plik z porownaniem poszegolnych sortowan
     */
    void create_benchmark_file();

private:

    /**
     * @brief benchark_with_filling zapisuje do pliku porownienie zosrtowan
     *          dla danej metody wypenienia tablicy
     * @param fill - wskaznik do funkcji wypelniającej tablice
     * @param file - zaczep do otwartego pliku
     * @param fill_metode - nazwa metody wypelnienia ktora zostanie umieszczona w pliku
     */
    void benchark_with_filling(void (CSortTablica::*fill)(int count), pat::File & file, std::string fill_metode);
    
};

#endif // CSORTTABLICA_H
