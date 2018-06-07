#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H

#include <stdexcept>

namespace pat {
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
