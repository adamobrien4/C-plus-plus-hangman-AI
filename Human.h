#ifndef HUMAN_H
#define HUMAN_H

#include "Agent.h"


class Human : public Agent
{
public:
    Human();
    char makeGuess();
};

#endif // HUMAN_H
