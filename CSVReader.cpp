#include "CSVReader.h"

CSVReader::CSVReader() {}

static vector<string> CSVReader::readSingleCSV(string filename) {
    vector<string> result;

    ifstream myFile(filename);
    if(!myFile.is_open()) throw runtime_error("Could not open file");

    // Helper vars
    string line, colname;
    string val;

    // Read data, line by line
    while(getline(myFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);


        // Keep track of the current column index
        int colIdx = 0;

        // Extract each integer
        while(ss >> val){

            // Add the current integer to the 'colIdx' column's values vector
            result.push_back(val);

            // If the next token is a comma, ignore it and move on
            if(ss.peek() == ',') ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    return result;
}

static vector<pair<char, float>> CSVReader::readCSVPair(string filename) {
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
