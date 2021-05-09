#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> read_csv(string filename){
    vector<string> result;

    // Create an input filestream
    ifstream myFile(filename);

    // Make sure the file is open
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

int main()
{
    srand(time(NULL));

    vector<string> words = read_csv("english_words.csv");
    string word = words[rand() % words.size()];

    // Holds how much of the word the user has guessed correctly
    string progress (word.length(), '?');
    int correct_chars = 0;
    char guess;
    int lives = 6;

    while(lives > 0) {
        cout << "----------------------------------------" << endl;
        cout << "Remaining Guesses: " << lives << endl;
        cout << progress << endl;
        cout << "Guess a letter: ";
        cin >> guess;

        bool correct_guess = false;
        for(int i = 0; i < word.length(); i++) {
            if(word[i] == guess) {
                progress[i] = guess;
                correct_chars++;
                correct_guess = true;
            }
        }

        if(!correct_guess) {
            lives--;
        }

        if(correct_chars == word.size()) {
            cout << "Congratulations! The word was " << word << endl;
            return 0;
        }
    }

    cout << "The word was " << word << ". Game Over!" << endl;

    return 0;
}
