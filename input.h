#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <bits/stdc++.h>
#include "inputexception.h"

/**
 * @brief The Input class
 *  Klasa wczytywania liczb całkowitych ze standartowego wejscia
 */
class Input
{
    int _max, _min;
public:
    Input();
    /**
     * @brief Input
     * @param min minimalna akceptowana liczba
     * @param max maxymalna akceptowana liczba
     */
    Input(int min, int max);

    /**
     * @brief set_max ustawia maksymalna akceptowalną wartosc
     * @param max - wartosc
     */
    void set_max(int max);

    /**
     * @brief set_max ustawia minimalna akceptowalną wartosc
     * @param min - wartosc
     */
    void set_min(int min);

    /**
     * @brief operator () pobiera liczbe ze standartowego wejscia
     * @return liczba
     */
    int operator ()();
};

#endif // INPUT_H
