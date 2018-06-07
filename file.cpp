#include "file.h"

pat::File::File()
{

}

bool pat::File::load(std::string dir)
{
    if(file.is_open())
        file.close();

    if(dir.find(".txt") == std::string::npos)
    {
        std::cout<<"add .txt? (t/n) >";
        char temp = 0;
        while(temp != 't' && temp != 'n')
        {
            std::cin>>temp;
            if(temp == 't')
                dir+= ".txt";
        }
    }

    if(dir.find("./") == std::string::npos)
        dir = "./" + dir;

    this->dir=dir;

    file.open(dir, std::ios::in);

    if(!file.good())
        throw pat::FileException(std::string("Cannot load the file: ") + dir);

    std::cout<<"loaded: "<<dir<<std::endl;
    return true;
}

/*
 * file creating
 * @param dir file directory
 * @return is created
 */
bool pat::File::create(std::string dir)
{
    if(dir.find(".txt") == std::string::npos)
    {
        std::cout<<"add .txt? (t/n) >";
        char temp = 0;
        while(temp != 't' && temp != 'n')
        {
            std::cin>>temp;
            if(temp == 't')
                dir+= ".txt";
        }
    }

    if(dir.find("./") == std::string::npos)
        dir = "./" + dir;

    if(file.is_open())
        file.close();

    this->dir=dir;

    file.open(dir, std::ios::out);
    if(!file.good())
        throw pat::FileException(std::string("Cannot create the file: ") + dir);

    std::cout<<"created:  "<<dir<<std::endl;
    return true;
}

bool pat::File::close()
{
    file.close();
    return true;
}

std::fstream &pat::File::getFstream()
{
    return file;
}






