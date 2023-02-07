#include <string>
#include <iostream>

namespace sdds
{
    struct NameTag
    {
        NameTag();
        NameTag(std::string name);
        NameTag(std::string name, int extension);
        ~NameTag();
        NameTag &read();
        void print();

        std::string name;
        int extension;
    };
}