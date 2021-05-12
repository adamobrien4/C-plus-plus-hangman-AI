#include "AgentTwo.h"

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// TODO: Move to csv reader class
vector<pair<char, float>> read_csv_pair(string filename)
{
  vector<pair<char, float>> result;

  ifstream myFile(filename);
  if (!myFile.is_open())
    throw runtime_error("Could not open file");

  // Helper vars
  string line;
  string val;

  // Read data, line by line
  while (getline(myFile, line))
  {
    char c = line.substr(0, 1)[0];
    float f = stof(line.substr(2));
    result.push_back(make_pair(c, f));
  }

  // Close file
  myFile.close();

  return result;
}

AgentTwo::AgentTwo() {
    letterDist = read_csv_pair("letter-dist.csv");
}

char AgentTwo::makeGuess() {
    char guess = letterDist[guessCounter].first;
    guessCounter++;
    return guess;
}
