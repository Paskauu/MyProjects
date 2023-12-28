#include <iostream>     // std::cout & std::cin
#include <vector>       // std::vector
#include <cmath>        // Math Operators
#include <algorithm>    // std::find

int main() {
    char Operator;
    std::string Command;
    double Number;
    double Result; 
    std::string ValidOperators = "+-*/^";
    std::string ValidCommands = "yn";
    
    Result = std::numeric_limits<double>::quiet_NaN();
    
    do {
        do {
            std::cout << "Enter a digit: ";
            std::cin.clear();
            if (std::cin >> std::ws >> Number) {
                break;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again.\n";
            }
        } 
        while(true);
        
        if(!std::isnan(Result)) {
            switch(Operator){
                case '+':    
                    Result += Number;
                    break;
                case '-':  
                    Result -= Number;
                    break;
                case '*':
                   Result *= Number;
                    break;
                case '/':
                    Result /= Number;
                    break;
                case '^':
                    Result = pow(Result,Number);
                    break;
            }
            
            std::cout << "Result: " << Result << std::endl;
            do {
                std::cout << "Exit? [y] [n] ";
                std::cin.clear();
                std::cin >> std::ws >> Command;
                if(ValidCommands.find(Command) != std::string::npos) {
                    break;
                } else {
                    std::cin.clear();
                    std::cout << "Invalid input. Try again.\n";
                }
            }
            while (true);
            if(Command == "y"){
                break;
            }
        }
        
        do {
            std::cin.clear();
            std::cout << "Enter the operator: ";
            std::cin >> std::ws >> Operator;
            if(ValidOperators.find(Operator) != std::string::npos) {
                break;   
            } else {
                std::cin.clear();
                std::cout << "Invalid input. Try again.\n";
            }
        }
        while(true);
        
        if (std::isnan(Result)) {
            Result = Number;
        }
    }
    while(true);
}