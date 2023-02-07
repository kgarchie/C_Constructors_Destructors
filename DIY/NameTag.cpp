#include <limits>
#include "NameTag.h"

namespace sdds
{

    NameTag::NameTag() : extension(0) {}

    NameTag::NameTag(std::string name) : name(name), extension(0) {}

    NameTag::NameTag(std::string name, int extension) : name(name), extension(extension) {}

    NameTag::~NameTag() {}

    NameTag &NameTag::read()
    {
        std::cout << "Please enter the name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        if (name.length() > 40)
        {
            name = name.substr(0, 40);
        }
        char answer;
        std::cout << "Would you like to enter an extension? (Y)es/(N)o: ";
        std::cin >> answer;
        while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
        {
            std::cout << "Only (Y) or (N) are acceptable, try again: ";
            std::cin >> answer;
        }
        if (answer == 'Y' || answer == 'y')
        {
            int input;
            std::cout << "Please enter a 5 digit phone extension: ";
            std::cin >> input;
            while (std::cin.fail() || input < 10000 || input > 99999)
            {
                if (std::cin.fail())
                {
                    std::cout << "Bad integer value, try again: ";
                }
                else
                {
                    std::cout << "Invalid value [10000<=value<=99999]: ";
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> input;
            }
            extension = input;
        }
        return *this;
    }

    void NameTag::print()
    {
        if (name.empty())
        {
            std::cout << "EMPTY NAMETAG!" << std::endl;
            return;
        }
        std::cout << "+";
        for (int i = 0; i < 40; i++)
        {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;
        std::cout << "|";
        for (int i = 0; i < 40; i++)
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        std::cout << "|";
        if (name.length() < 20)
        {
            for (int i = 0; i < (20 - name.length()) / 2; i++)
            {
                std::cout << " ";
            }
            std::cout << name;
            for (int i = 0; i < (20 - name.length()) / 2; i++)
            {
                std::cout << " ";
            }
            if ((20 - name.length()) % 2 == 1)
            {
                std::cout << " ";
            }
        }
        else
        {
            std::cout << name.substr(0, 20);
        }
        std::cout << "|" << std::endl;
        std::cout << "|";
        for (int i = 0; i < 40; i++)
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        std::cout << "|";
        if (extension != 0)
        {
            std::cout << "Extension: " << extension;
        }
        for (int i = 0; i < 40; i++)
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        std::cout << "+";
        for (int i = 0; i < 40; i++)
        {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;
    }
}