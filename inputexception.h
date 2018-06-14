#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H

#include <stdexcept>

namespace pat {
    /**
     * @brief The InputException class
     *  Klasa wyjątku standartowego wejscia
     */
    class InputException: public std::logic_error
    {
    public:
        InputException()
            :logic_error("bad input"){}
        InputException(const std::string &msg)
            :logic_error(msg){}
    };
}

#endif // INPUTEXCEPTION_H
