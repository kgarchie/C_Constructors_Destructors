// tournament.cpp
#include "tournament.h"
#include <cstring>

namespace sdds
{
  // First, it will check the validity of all the received arguments. Tournament name should be valid and non-empty Cstring. Number of teams should be greater than zero.
  // It will set m_num to the corresponding argument value.
  // Then it will dynamically allocate memory for tournament name in the tournament name pointer attribute and then copies the content of the tournament name argument into the newly allocated memory.
  // It will dynamically allocate an array of soccer team pointed by m_soccer member variable. The length of this array will be m_num.
  // Lastly, add all the teams to the dynamically allocated array of m_soccer.
  // If any of the arguments are not valid it will set the Tournament to an empty state.
  void Tournament::setTournament(const char *name, int noOfteam, const SoccerTeam *soccer)
  {
    if (name != nullptr && name[0] != '\0' && noOfteam > 0 && soccer != nullptr)
    {
      m_num = noOfteam;
      delete[] m_name;
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
      delete[] m_soccer;
      m_soccer = new SoccerTeam[m_num];
      for (int i = 0; i < m_num; i++)
      {
        m_soccer[i] = soccer[i];
      }
    }
    else
    {
      setEmpty();
    }
  }

  // Sets the Tournamnet object to an Empty State. Do this by setting the m_name and m_soccer to null and m_num to 0.
  void Tournament::setEmpty()
  {
    delete[] m_name;
    m_name = nullptr;
    delete[] m_soccer;
    m_soccer = nullptr;
    m_num = 0;
  }

  // Returns true if m_name and m_soccer is not null and m_num is grater than 0.
  bool Tournament::isEmpty() const
  {
    return m_name == nullptr && m_soccer == nullptr && m_num == 0;
  }

  // By default a Tournament is set to the empty state (as in setEmpty())
  Tournament::Tournament()
  {
    setEmpty();
  }

  // After checking the validity it will set the tournament name,number of teams and soccer teams information to the appropriate data members
  // or else it will set the tournament to the empty state. (reuse your setter fucntions)
  Tournament::Tournament(const char *name, int noOfteam, const SoccerTeam *soccer)
  {
    setTournament(name, noOfteam, soccer);
  }

  // Deallocate the memory allocated by m_name and m_soccer.
  Tournament::~Tournament()
  {
    delete[] m_name;
    delete[] m_soccer;
  }

  // This function will find out the winner between 2 soccer teams by having matches. It will loop through all the teams.
  // First it will check which team is having more no of fouls.
  // If first team is having less fouls then second team then, second team`s no of foul will increase by double and fine will be increased by 20%
  // First team`s goal will be increased by 1.
  // If seconds team`s no of foul exceed the MAX_FOUL then this team will become a invalid team. You can do this by setting the number to foul to an invalid value.
  // At the end it will return the reference of the current object.
  Tournament &Tournament::match(const SoccerTeam *ls)
  {
    if (!isEmpty() && ls != nullptr)
    {
      for (int i = 0; i < m_num; i++)
      {
        if (m_soccer[i].fouls() < ls[i].fouls())
        {
          ls[i].setFine(ls[i].m_fines, ls[i].m_noFouls * 2);
          ls[i].m_goals++;
        }
        else if (ls[i].fouls() > MAX_FOUL)
        {
          ls[i].setFine(ls[i].m_fines, -1);
        }
      }
    }
    return *this;
  }

  // If Tournament object is valid
  // a) prints "Tournament name: " then tournament name
  // b) prints "list of the teams" after that a newline
  // c) prints "Fines" with width 45 and fill with empty spaces.
  // d) prints "Fouls" with width 10 and fill with empty spaces.
  // e) prints "Goals" with width 10 and fill with empty spaces.
  // e) prints all the soccer teams information. For details see the sample output.
  // otherwise prints, "Invalid Tournament".
  // At the end return the reference of the ostream object.
  std::ostream &Tournament::display() const
  {
    if (!isEmpty())
    {
      std::cout << "Tournament name : " << m_name << std::endl;
      std::cout << "list of the teams" << std::endl;
      std::cout << std::setw(45) << "Fines"
                << std::setw(10) << "Fouls"
                << std::setw(10) << "Goals" << std::endl;
      for (int i = 0; i < m_num; i++)
      {
        m_soccer[i].display();
      }
    }
    else
    {
      std::cout << "Invalid Tournament" << std::endl;
    }

    return std::cout;
  }
}


// Delete this
// #include "Tournament.h"
// #include "soccerTeam.h"

// #include <cstring>
// #include <iostream>

// using namespace std;
// using namespace sdds;

// namespace sdds
// {
// 	void Tournament::setTournament(const char *name, int noOfteam, const SoccerTeam *soccer)
// 	{
// 		setEmpty();
// 		if (name != nullptr && strlen(name) > 0 && noOfteam > 0 && soccer != nullptr)
// 		{
// 			m_name = new char[strlen(name) + 1];
// 			strcpy(m_name, name);
// 			m_num = noOfteam;
// 			m_soccer = new SoccerTeam[m_num];
// 			for (int i = 0; i < m_num; i++)
// 			{
// 				m_soccer[i] = soccer[i];
// 			}
// 		}
// 	}

// 	void Tournament::setEmpty()
// 	{
// 		delete[] m_name;
// 		m_name = nullptr;
// 		delete[] m_soccer;
// 		m_soccer = nullptr;
// 		m_num = 0;
// 	}

// 	bool Tournament::isEmpty() const
// 	{
// 		return m_name == nullptr && m_soccer == nullptr && m_num == 0;
// 	}

// 	Tournament &Tournament::match(const SoccerTeam *ls)
// 	{
// 		for (int i = 0; i < m_num; i++)
// 		{
// 			if (m_soccer[i].fouls() < ls[i].fouls())
// 			{
// 				m_soccer[i].setFine(m_soccer[i].m_fines, (ls[i].m_noFouls * 2));
// 				m_soccer[i].calcFines();
// 				m_soccer[i].m_goals++;
// 			}
// 			if (ls[i].fouls() > MAX_FOUL)
// 			{
// 				ls[i].setFine(ls[i].m_fines, -1);
// 			}
// 		}
// 		return *this;
// 	}

// 	ostream &Tournament::display() const
// 	{
// 		if (!isEmpty())
// 		{
// 			cout << "Tournament Name : " << m_name << endl;
// 			cout << "List of the teams" << endl;
// 			cout << "                                         Fines     Fouls     Goals" << endl;
// 			for (int i = 0; i < m_num; i++)
// 			{
// 				cout << "Team[" << i + 1 << "] : ";
// 				m_soccer[i].display() << endl;
// 			}
// 		}
// 		else
// 		{
// 			cout << "Invalid Tournament" << endl;
// 		}
// 		return cout;
// 	}

// 	Tournament::Tournament()
// 	{
// 		setEmpty();
// 	}

// 	Tournament::Tournament(const char *name, int noOfteam, const SoccerTeam *soccer)
// 	{
// 		setTournament(name, noOfteam, soccer);
// 	}

// 	Tournament::~Tournament()
// 	{
// 		setEmpty();
// 	}
// } // namespace sdds