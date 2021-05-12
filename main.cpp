#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>

#include "Agent.h"
#include "Human.h"
#include "AgentOne.h"
#include "AgentTwo.h"

using namespace std;

// ------ Global Variables

vector<string> words;
string word;
Agent *agent;
bool debug = true;



// ------ Program Functions

// TODO: Make generic read_csv function to handle different types of values
vector<string> read_csv(string filename){
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

bool guess_letter(char letter) {

    if(debug) {
        cout << "Guess was " << letter << endl;
    }

    bool correct_guess = false;
    for(int i = 0; i < word.length(); i++) {
        if(word[i] == letter) {
            agent->updateProgress(i, letter);
            correct_guess = true;
        }
    }

    if(!correct_guess) {
        agent->decrementLives();
    }

    if(agent->getCorrectChars() == word.size()) {
        return true;
    }
    return false;
}

// ------ Main Function

int main()
{
    srand(time(NULL));

    words = read_csv("english_words.csv");
    word = words[rand() % words.size()];

    // Load CSV file containing letter distribution from https://en.wikipedia.org/wiki/Letter_frequency - Relative frequency in the English language on Dictionaries.

    int game_mode;

    cout << "Game Mode:" << endl;
    cout << "0: Player vs. Computer" << endl;
    cout << "1: Agent 1" << endl;
    cout << "2: Agent 2" << endl;
    cout << "3: Agent 3" << endl;
    cin >> game_mode;

    switch(game_mode) {
        case 0:
            {
                // Holds how much of the word the user has guessed correctly
                agent = new Human();
                cout << "Mode 0" << endl;
                break;
            }
        case 1:
            {
                agent = new AgentOne();
                cout << "Mode 1" << endl;
                break;
            }
        case 2:
            {
                agent = new AgentTwo();
                cout << "Mode 2" << endl;
                break;
            }
        case 3:
            cout << "Mode 3" << endl;
            break;
        default:
            cout << "Invalid game mode selected.";
            return 0;
    }

    agent->setWordLength(word.length());
    agent->setLives(8);

    cout << "Starting Game" << endl;

    while(agent->getLives() > 0) {
        if(guess_letter(agent->makeGuess())) {
            cout << "The word was " << word << endl;
            cout << "Congratulations! Game completed in " << agent->getGuessCount() << " guesses."  << endl;
            cout << "Agent's progress " << agent->getProgress() << endl;
            return 0;
        }
    }

    cout << "The word was " << word << ". Game Over!" << endl;
    cout << "Agent's progress " << agent->getProgress() << endl;

    return 0;
}
