#pragma once
#include <iostream>

namespace sdds
{
    const int MAX_NAME = 40;
    const int EXT_LEN = 5;

    class NameTag
    {
        char m_name[MAX_NAME + 1];
        int m_extension;

    public:
        NameTag();
        NameTag(const char *name);
        NameTag(const char *name, int extension);
        ~NameTag();
        NameTag &read();
        void print() const;
    };
}