#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "fileexception.h"

namespace pat
{
    /**
     * @brief The File class
     *  Klasa obslugi plikow
     */
    class File
    {
        std::string dir;
        std::fstream file;

    public:
        File();
        /**
         * @brief load otwiera istniejący plik
         * @param dir - scierzka do pliku
         * @return true gdy udalo sie otworzyc lub false w przeciwnym wypadku
         */
        bool load(std::string dir);

        /**
         * @brief create tworzy nowy plik i otwiera go
         * @param dir - scierzka do pliku
         * @return true gdy udalo sie stworzyc lub false w przeciwnym wypadku
         */
        bool create(std::string dir);

        /**
         * @brief close zamyka pliku
         * @return true
         */
        bool close();

        /**
         * @brief getFstream
         * @return otwarty strumien pliku
         */
        std::fstream & getFstream();

        /**
         *  @brief getVal
         *
         *  @return zwraca element odczytany z pliku
         */
        template<class T >
        T getVal()
        {
           T temp;
           file>>temp;
           return temp;
        }

        /**
         *  @brief putVal wpisuje do pliku
         *  @param val element do wpisania
         */
        template<class T >
        void putVal(T val)
        {
           file<<val;
        }


        /**
         *  @brief get_array_line wczytuje tablice elementow z pliku
         *  @param array wskaznik na tablice
         *  @param size wielkosc tablicy
         *  @return powodzenie
         */
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
