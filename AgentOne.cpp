#include "AgentOne.h"

AgentOne::AgentOne() {}

char AgentOne::makeGuess() {
    guessCounter++;
    return (rand() % 26) + 'a';
}
