#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H

#include <stdexcept>

namespace pat {
    /**
     * @brief The FileException class
     *  Klasa wyjątku rzucanego podczas blędu w plikach
     */
    class FileException : public std::runtime_error
    {
    public:
        FileException()
            : std::runtime_error("file error"){}
        FileException(const std::string & msg)
            : std::runtime_error(msg){}
    };
}

#endif // FILEEXCEPTION_H
