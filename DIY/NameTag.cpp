#include "NameTag.h"
#include <cstring>

using namespace std;
using namespace sdds;

NameTag::NameTag()
{
    m_name[0] = '\0';
    m_extension = 0;
}

NameTag::NameTag(const char *name)
{
    if (name == nullptr)
    {
        m_name[0] = '\0';
    }
    else
    {
        strncpy(m_name, name, MAX_NAME);
        m_name[MAX_NAME] = '\0';
    }
    m_extension = 0;
}

NameTag::NameTag(const char *name, int extension)
{
    if (name == nullptr)
    {
        m_name[0] = '\0';
    }
    else
    {
        strncpy(m_name, name, MAX_NAME);
        m_name[MAX_NAME] = '\0';
    }
    m_extension = extension;
}

NameTag::~NameTag()
{
    m_name[0] = '\0';
    m_extension = 0;
}

NameTag &NameTag::read()
{
    cout << "Please enter the name: ";
    cin.getline(m_name, MAX_NAME + 1);
    cout << "Would you like to enter an extension? (Y)es/(N)o: ";
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        cout << "Please enter a 5 digit phone extension: ";
        int ext;
        cin >> ext;
        while (ext < 10000 || ext > 99999)
        {
            cout << "Invalid value [10000<=value<=99999]: ";
            cin >> ext;
        }
        m_extension = ext;
    }
    else
    {
        m_extension = 0;
    }
    return *this;
}

void NameTag::print() const
{
    int nameLen = strlen(m_name);
    int remainLen = MAX_NAME - nameLen;

    cout << "+";
    for (int i = 0; i < MAX_NAME + 2; i++)
    {
        cout << "-";
    }
    cout << "+" << endl;
    cout << "|";
    for (int i = 0; i < remainLen / 2; i++)
    {
        cout << " ";
    }
    cout << m_name;
    for (int i = 0; i < remainLen / 2; i++)
    {
        cout << " ";
    }
    if (remainLen % 2 != 0)
    {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|";
    for (int i = 0; i < MAX_NAME + 2; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
    if (m_extension != 0)
    {
        cout << "| Extension: " << m_extension;
        for (int i = 0; i < MAX_NAME - 10; i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }
    else
    {
        cout << "| Extension: N/A";
        for (int i = 0; i < MAX_NAME - 11; i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << "|";
    for (int i = 0; i < MAX_NAME + 2; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "+";
    for (int i = 0; i < MAX_NAME + 2; i++)
    {
        cout << "-";
    }
    cout << "+" << endl;
}