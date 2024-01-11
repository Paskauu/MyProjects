#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

bool InvalidInpud(bool Input) {
    if(Input) {
        return false;
    } else {
        std::cout << '\n' << "Invalid Input."; 
        std::cout << '\n' <<"Try again!";
        return true;
    }
}

char RockPaperScissors() {
    srand(time(NULL));
    int Choice = rand()%3+1;
    switch(Choice){
        case 1: return 'R';
        case 2: return 'P';
        case 3: return 'S';
    }
}

std::string TextRockPaperScissors(char Choice) {
    switch(Choice){
        case 'R': return "🪨";
        case 'P': return "🧻";
        case 'S': return "✂️";
    }
}

std::string GameResult(char PlayerMove, char ComputerMove){
    std::string WhoWins;
    std::string PlayerWins = "Player Wins!";
    std::string ComputerWins = "Computer Wins!";
    std::string Tie = "Tie";
    std::cout << '\n' << "You -> " << TextRockPaperScissors(PlayerMove);
    std::cout << '\n' << "Computer -> " << TextRockPaperScissors(ComputerMove) << '\n';
    switch(ComputerMove == PlayerMove){
        case true: return Tie;
        case false:
            switch(ComputerMove){
                case 'R': 
                    switch(PlayerMove){
                        case 'P': return PlayerWins;
                        case 'S': return ComputerWins;
                    }
                case 'P':
                    switch(PlayerMove){
                        case 'S': return PlayerWins;
                        case 'R': return ComputerWins;
                    }
                case 'S':
                    switch(PlayerMove){
                        case 'R': return PlayerWins;
                        case 'P': return ComputerWins;
                    }
            }
    }
}

int main() {
    bool Continue = true;
    do {
        char Player;
        char Computer;
        char Command;
        std::string ValidCommand = "YN";
        std::string ValidInput = "RPS";
        do{
            std::cout << '\n' <<"************************";
            std::cout << '\n' <<"🪨  (R) 🧻 (P) ✂️  (S)";
            std::cout << '\n' <<"************************";
            std::cout << '\n' <<"-> ";
            std::cin >> Player;
            Player = toupper(Player);
        } while (InvalidInpud(Player && (ValidInput.find(Player) != std::string::npos)));
        Computer = RockPaperScissors();
        std::cout << GameResult(Player, Computer);
        do {
            std::cout << '\n' << "Continue? [Y] [N]";
            std::cout << '\n' << "-> ";
            std::cin >> Command;
            Command = toupper(Command);
        } while(InvalidInpud(Command && (ValidCommand.find(Command) != std::string::npos)));
        Command == 'N' ? Continue = false : Continue;
    } while (Continue);
    return 0;
}