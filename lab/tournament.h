#ifndef SDDS_TOURNAMENT_H
#define SDDS_TOURNAMENT_H

#include "soccerTeam.h"
#include <iostream>
#include <iomanip>

namespace sdds
{
    class Tournament
    {
    private:
        char *m_name;
        int m_num;
        SoccerTeam *m_soccer = nullptr;

    public:
        Tournament();
        Tournament(const char *name, int noOfteam, const SoccerTeam *soccer);
        ~Tournament();
        void setTournament(const char *name, int noOfteam, const SoccerTeam *soccer);
        void setEmpty();
        bool isEmpty() const;
        Tournament &match(const SoccerTeam *ls);
        std::ostream &display() const;
    };
}
#endif
