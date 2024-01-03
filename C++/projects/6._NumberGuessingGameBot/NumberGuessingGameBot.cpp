#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>

int main() {
    srand(time(NULL));
    int MaxNumToGuess = 100;
    int MinNumToGuess = 1;
    int NumToGuess;
    int NumChances;
    int NumGuessed;
    int HigherNumGuessed;
    int LowerNumGuessed;
    int* pNumToGuess;
    int* pNumChances;
    int* pNumGuessed;
    int* pMaxNumToGuess = &MaxNumToGuess;
    int* pMinNumToGuess = &MinNumToGuess;
    int* pHigherNumGuessed = &HigherNumGuessed;
    int* pLowerNumGuessed = &LowerNumGuessed;
    std::string Command;
    std::string ValidCommand = "YN";

    std::cout << "\tWELCOME TO NUMBER GUESSING GAME!\n";
    std::cout << "\tGUESS A NUMBER BETWEEN 1 AND 100!\n";

    do {
        HigherNumGuessed = MaxNumToGuess;
        LowerNumGuessed = MinNumToGuess;
        NumChances = 1;
        pNumChances = &NumChances;
        NumToGuess = rand() % *pMaxNumToGuess + *pMinNumToGuess;
        pNumToGuess = &NumToGuess;

        do {
            std::cin.clear();
            std::cout << "What number I'm thinking?\n";
            NumGuessed = rand() % *pHigherNumGuessed + *pLowerNumGuessed;
            pNumGuessed = &NumGuessed;
            std::cout << "Number Guessed:\n" << *pNumGuessed;

            if(*pNumGuessed == *pNumToGuess) {
                std::cout << "\n\tCONGRATULATIONS!\n\tYOU WON!\n";
                std::cout << "Count of Guesses: " << *pNumChances << "\n";
                break;
            } else {
                std::cout << "\n\tWRONG ONE!\n";
                *pNumChances += 1;
                std::cout << "Count of Guesses: "<< *pNumChances << "\n"; 

                if(*pNumGuessed < *pNumToGuess) {
                    std::cout << "I'm thinking in a number above "<< *pNumGuessed << "\n\n";
                    *pHigherNumGuessed -= (*pNumGuessed - *pLowerNumGuessed);
                    *pLowerNumGuessed = *pNumGuessed + 1;
                } else {
                    std::cout << "I'm thinking in a number below "<< *pNumGuessed << "\n\n";
                    *pHigherNumGuessed -= *pHigherNumGuessed - (*pNumGuessed - *pLowerNumGuessed);
                }
                
            }

        } while (true);

        do {
            std::cin.clear();
            std::cout << "Play again? [Y] [N]\n";
            std::cin >> Command;
            std::transform(Command.begin(),Command.end(),Command.begin(),::toupper);
            if (ValidCommand.find(Command) != std::string::npos) {
                break;
            } else {
                std::cin.clear();
                std::cout << "Invalid input. Try again.\n";
            }
        } while (true);

        if (Command == "N") {
            break;
        } 

    } while (true);
}