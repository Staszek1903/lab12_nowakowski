#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <bits/stdc++.h>
#include "inputexception.h"

class Input
{
    int _max, _min;
public:
    Input();
    Input(int min, int max);
    void set_max(int max);
    void set_min(int min);
    int operator ()();
};

#endif // INPUT_H
