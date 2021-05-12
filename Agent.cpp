#include "Agent.h"

using namespace std;

Agent::Agent() {}

void Agent::setWordLength(int length) {
    wordLength = length;
    for(int i = 0; i < length; i++) {
        progress += '?';
    }
}

int Agent::getCorrectChars() {
    return correctChars;
}

void Agent::decrementLives() {
    lives--;
}
void Agent::setLives(int l) {
    lives = l;
}
int Agent::getLives() {
    return lives;
}

int Agent::getGuessCount() {
    return guessCounter;
}

void Agent::updateProgress(int index, char letter) {
    progress[index] = letter;
    correctChars++;
}

string Agent::getProgress() {
    return progress;
}
