#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

char RockPaperScissors() {
    srand(time(NULL));
    int Choice = rand()%3+1;
    char TextChoice;
    switch(Choice){
        case 1: TextChoice = 'r'; break;
        case 2: TextChoice = 'p'; break;
        case 3: TextChoice = 's'; break;
    }
    return TextChoice;
}

std::string GameResult(char ComputerMove, char PlayerMove){
    switch(ComputerMove == PlayerMove){
        case true: std::cout << "Tie"; break;
        case false:
            switch(ComputerMove){
                case 'r': 
                    switch(PlayerMove){
                        case 'p': std::cout << "You Win"; break;
                        case 's': std::cout << "You Lose"; break;
                    }
                case 'p':
                    switch(PlayerMove){
                        case 's': std::cout << "You Win"; break;
                        case 'r': std::cout << "You Lose"; break;
                    }
                case 's':
                    switch(PlayerMove){
                        case 'r': std::cout << "You Win"; break;
                        case 'p': std::cout << "You Lose"; break;
                    }
            }
    }
    return 0;
}

int main() {
    char Player;
    char Computer;
    std::cout << '\n' <<"Rock (r) Paper (p) Scissors (s)";
    std::cout << '\n' <<"-> ";
    // std::cin >> Player;
    Player = 'r';
    Computer = RockPaperScissors();
    GameResult(Player, Computer);
    return 0;
}