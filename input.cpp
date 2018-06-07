#include "input.h"

Input::Input()
    :_max(INT_MAX), _min(-INT_MAX)
{
    std::cin.exceptions(std::istream::failbit | std::istream::badbit);
}

Input::Input(int min, int max)
    :_max(max), _min(min)
{
    std::cin.exceptions(std::istream::failbit | std::istream::badbit);
}

void Input::set_max(int max)
{
    _max = max;
}

void Input::set_min(int min)
{
    _min = min;
}

int Input::operator ()()
{
    int val;
    std::cin>>val;
    if(val>_max || val<_min){
        throw pat::InputException("number out of range");
    }
}
