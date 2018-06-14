#ifndef CTABLICA_H
#define CTABLICA_H

#include <iostream>
#include <vector>
#include <utility>

    /**
    * @brief CTablica zawiera algorytmy sortowania
    **/

class CTablica
{
   public:
    /**
    * @brief konstruktor
    **/
    CTablica();
    /**
    * brief tab - tablica, ktora zawiera liczby, majace zostac posortowane przez algorytm
    **/
    std::vector <int> tab;
    /**
     * @brief quick_sort_lomuto sortuje tablice szybkim sortowanie wersja bubble sort
     */
    std::pair <int, int> bubble_sort();
    /**
     * @brief quick_sort_lomuto sortuje tablice szybkim sortowanie wersja lomuto
     * @param index A - pierwszy indeks w tablicy
     * @param index B - ostatni indeks w tablicy
     */
    std::pair <int, int> quick_sort_lomuto(int indexA, int indexB);
    /**
     * @brief quick_sort_lomuto sortuje tablice szybkim sortowanie wersja hoare
     * @param index A - pierwszy indeks w tablicy
     * @param index B - ostatni indeks w tablicy
     */
    std::pair <int, int> quick_sort_hoare(int indexA, int indexB);
    /**
     * @brief quick_sort_lomuto sortuje tablice szybkim sortowanie wersja heap sort
     */
    std::pair <int, int> heap_sort();

   private:
    /**
     * @brief heapify
     * @param heapSize - rozmiar kopiec
     * @param i - pierwszy indeks w tablicy
     */
    std::pair<int,int> heapify(int heapSize, int i);


};

#endif // CTABLICA_H
