#ifndef AGENTTWO_H
#define AGENTTWO_H

#include<vector>

#include "Agent.h"

class AgentTwo : public Agent
{
    public:
        AgentTwo();
        char makeGuess();

    protected:

    private:
        std::vector<std::pair<char, float>> letterDist;
};

#endif // AGENTTWO_H
