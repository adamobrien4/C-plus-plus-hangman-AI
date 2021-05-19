#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>

using namespace std;

class CSVReader
{
    public:
        CSVReader();
        vector<string> readSingleCSV(string filename);
        vector<pair<char, float>> readCSVPair(string filename);

    protected:

    private:
};

#endif // CSVREADER_H
