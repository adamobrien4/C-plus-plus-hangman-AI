#include "AgentTwo.h"

#include <vector>
#include <fstream>
#include <iostream>

#include "CSVReader.h"

using namespace std;

AgentTwo::AgentTwo() {
    letterDist = CSVReader::readCSVPair("letter-dist.csv");
}

char AgentTwo::makeGuess() {
    char guess = letterDist[guessCounter].first;
    guessCounter++;
    return guess;
}
