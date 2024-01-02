#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>

int main() {
    srand(time(NULL));
    int NumToGuess;
    int NumChances;
    int NumGuessed;
    std::string Command;
    std::string ValidCommand = "YN";

    std::cout << "\tWELCOME TO NUMBER GUESSING GAME!\n";
    std::cout << "\tGUESS A NUMBER BETWEEN 1 AND 100!\n";

    do {
        std::cout << "How many chances do you want?\n";
        std::cin >> NumChances;
        NumToGuess = rand() % 100 + 1;

        do {
            do {
                std::cin.clear();
                std::cout << "What number I'm thinking?\n";
                std::cin >> NumGuessed;
                if (NumGuessed) {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid input. Try again.\n";
                }
            } while (true);

            if(NumGuessed == NumToGuess) {
                std::cout << "\tCONGRATULATIONS!\n\tYOU WON!\n";
                std::cout << "Remain guesses: " << NumChances << "\n";
                break;
            } else {
                std::cout << "\tWRONG ONE!\n";
                NumChances -= 1;
                std::cout << "Ramain guesses: "<< NumChances << "\n"; 
                
                if(NumChances == (int) 0) {
                    std::cout << "\tYOU LOSE!\n";
                    std::cout << "I was thinking in: " << NumToGuess << "\n";
                    break;
                }
                
                if(NumGuessed < NumToGuess) {
                    std::cout << "I'm thinking in a number above "<< NumGuessed << "\n";
                } else {
                    std::cout << "I'm thinking in a number below "<< NumGuessed << "\n";
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