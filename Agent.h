#ifndef AGENT_H
#define AGENT_H

#include<string>

class Agent
{
public:
    Agent();

    void setWordLength(int length);

    int getCorrectChars();

    void decrementLives();
    void setLives(int l);
    int getLives();
    std::string getProgress();
    int getGuessCount();

    void updateProgress(int index, char letter);

    virtual char makeGuess() {
        return '!';
    }
protected:
    std::string progress;
    int wordLength {0};
    int correctChars {0};
    int lives {0};
    int guessCounter {0};
};

#endif // AGENT_H
