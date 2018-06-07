#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "fileexception.h"

namespace pat
{
    class File
    {
        std::string dir;
        std::fstream file;

    public:
        File();
        bool load(std::string dir);
        bool create(std::string dir);
        bool close();
        std::fstream & getFstream();

        template<class T >
        T getVal()
        {
           T temp;
           file>>temp;
           return temp;
        }

        template<class T >
        void putVal(T val)
        {
           file<<val;
        }


        template<class T>
        bool get_array_line(T **array, int size)
        {
           if(array)
               delete [] *array;

           *array = new T[size];

           std::string line;
           std::stringstream line_stream;

           while(file.peek() == '\n' || file.peek() == ' ')
               file.get();

           std::getline(file,line);
           line_stream<<line;

           //std::cout<<line<<std::endl;

           //std::cout<<size<<std::endl;

           for(int i=0; i<size; ++i)
           {
               T temp;
               if(line_stream.eof())
               {
                   std::cout<<"not enough emements in line FILE: "<<dir<<std::endl;
                   return false;
               }

               line_stream>>temp;

               //std::cout<<i<<"temp: "<<temp<<std::endl;

               array[0][i] = temp;
           }
           return true;
        }
    };
}


#endif // FILE_H
