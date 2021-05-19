#include "Human.h"

#include <iostream>

Human::Human() {}

char Human::makeGuess()  {
    char guess;
    std::cout << "You have " << lives << " remaining guesses." << std::endl;
    std::cout << progress << std::endl;
    std::cout << "Make a guess: ";
    std::cin >> guess;

    guessCounter++;
    return guess;
}
