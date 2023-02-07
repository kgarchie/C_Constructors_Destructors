#include "soccerTeam.h"
#include <cstring>
#include <iomanip>

namespace sdds
{
  // sets team name, fines and fouls of the team
  void SoccerTeam::setTeam(const SoccerTeam &team)
  {
    setName(team.m_teamName);
    m_noFouls = team.m_noFouls;
    m_fines = team.m_fines;
    m_goals = team.m_goals;
  }

  // If the received name pointer is valid and not null it will copy the received name to the data member m_teamName
  void SoccerTeam::setName(const char *tname)
  {
    if (tname != nullptr && tname[0] != '\0')
    {
      strcpy(m_teamName, tname);
    }
  }

  // It will receive the information about fines and no of foul. After checking the validity it will set the values to the appropriate data members.
  // Fine and foul should be grater than and equal to zero. Otherwise, it will set the soccerTeam object to an empty state.
  void SoccerTeam::setFine(double fines, int foul)
  {
    if (fines >= 0 && foul >= 0)
    {
      m_fines = fines;
      m_noFouls = foul;
    }
    else
    {
      setEmpty();
    }
  }

  // Sets the soccerTeam object to an Empty State. Do this by setting the m_teamName to an empty Cstring, m_noFoul and m_fines to a negative number and m_goals to 0.
  void SoccerTeam::setEmpty()
  {
    m_teamName[0] = '\0';
    m_noFouls = -1;
    m_fines = -1;
    m_goals = 0;
  }

  // Returns true if m_teamName is not null, m_fines and m_noFouls is grater than 0.
  bool SoccerTeam::isEmpty() const
  {
    return m_teamName[0] == '\0' && m_fines < 0 && m_noFouls < 0;
  }

  // If this function is called it will increases the fine by 20% of the old fine value.
  void SoccerTeam::calcFines()
  {
    m_fines += m_fines * 0.2;
  }

  // It will return the m_noFoul
  int SoccerTeam::fouls() const
  {
    return m_noFouls;
  }

  // By default a soccerTeam is set to the empty state (as in setEmpty())
  SoccerTeam::SoccerTeam()
  {
    setEmpty();
  }

  // After checking the validity it will set the team`s name,fine and no of fouls to the appropriate data members
  // or else it will set the team to the empty state. (reuse your setter fucntions)
  SoccerTeam::SoccerTeam(const char *tname, double fines, int foul)
  {
    setName(tname);
    setFine(fines, foul);
  }

  // If a soccerTeam object is valid
  // a) prints m_teamName with width 30, left justified and fill with empty spaces.
  // b) prints m_fines with width 6 and after the decimal point 2 digits.
  // c) prints m_noFoul with width 6
  // d) prints m_fines with width 6
  // e) prints m_golas with width 10. If number of goals are greater than zero then it will print "w" besides the number.
  // otherwise prints, "Invalid Team".
  // At the end return the reference of the ostream object.
  std::ostream &SoccerTeam::display() const
  {
    if (!isEmpty())
    {
      std::cout << std::setw(30) << std::left << m_teamName;
      std::cout << std::setw(6) << std::right << std::fixed << std::setprecision(2) << m_fines;
      std::cout << std::setw(6) << m_noFouls;
      std::cout << std::setw(6) << m_fines;
      std::cout << std::setw(10) << (m_goals > 0 ? 'w' : ' ') << m_goals << std::endl;
    }
    else
    {
      std::cout << "Invalid Team" << std::endl;
    }
    return std::cout;
  }
}



// #include "soccerTeam.h"
// #include <cstring>
// #include <iomanip>

// namespace sdds
// {

//     void SoccerTeam::setTeam(const SoccerTeam &team)
//     {
//         setName(team.m_teamName);
//         setFine(team.m_fines, team.m_noFouls);
//     }

//     void SoccerTeam::setName(const char *tname)
//     {
//         if (tname != nullptr)
//         {
//             strncpy(m_teamName, tname, 40);
//             m_teamName[40] = '\0';
//         }
//     }

//     void SoccerTeam::setFine(double fines, int foul)
//     {
//         if (fines >= 0 && foul >= 0 && foul <= MAX_FOUL)
//         {
//             m_fines = fines;
//             m_noFouls = foul;
//         }
//         else
//         {
//             setEmpty();
//         }
//     }

//     void SoccerTeam::setEmpty()
//     {
//         m_teamName[0] = '\0';
//         m_noFouls = -1;
//         m_fines = -1.0;
//         m_goals = 0;
//     }

//     bool SoccerTeam::isEmpty() const
//     {
//         return m_teamName[0] == '\0' && m_noFouls < 0 && m_fines < 0;
//     }

//     void SoccerTeam::calcFines()
//     {
//         m_fines *= 1.2;
//     }

//     int SoccerTeam::fouls() const
//     {
//         return m_noFouls;
//     }

//     SoccerTeam::SoccerTeam()
//     {
//         setEmpty();
//     }

//     SoccerTeam::SoccerTeam(const char *tname, double fines, int foul)
//     {
//         setFine(fines, foul);
//         setName(tname);
//     }

//     std::ostream &SoccerTeam::display() const
//     {
//         if (!isEmpty())
//         {
//             os << std::left << std::setw(30) << m_teamName;
//             os << std::fixed << std::setprecision(2) << std::setw(6) << m_fines;
//             os << std::right << std::setw(6) << m_noFouls;
//             os << std::right << std::setw(6) << m_goals;
//             if (m_goals > 0)
//             {
//                 os << " W";
//             }
//         }
//         else
//         {
//             os << "Invalid Team";
//         }
//         return os;
//     }
// } // namespace sdds
