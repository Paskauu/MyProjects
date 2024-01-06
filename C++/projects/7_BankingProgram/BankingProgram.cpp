#include <iostream>
#include <cmath>
#include <iomanip>

double ValidInput(bool Verified) {
    if(Verified){
        return true;
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid input. Try again!";
        return false;
    }
}

int BankMenu() {
    int Choice;
    do {
        std::cout << '\n' << "********************";
        std::cout << '\n' << "      BANK MENU";
        std::cout << '\n' << "*******************";
        std::cout << '\n' << "1 -> Show Balance";
        std::cout << '\n' << "2 -> Deposit Money";
        std::cout << '\n' << "3 -> Withdraw Money";
        std::cout << '\n' << "4 -> Exit";
        std::cout << '\n' << "-> ";
        std::cin >> Choice;
    } while (!ValidInput(Choice && Choice <= 4));
    return Choice;
}

double Money(std::string Action, double CurrentAmount) {
    double Money;
    do {
        std::cout << '\n' << "Enter the amount to " << Action;
        std::cout << '\n' << "-> R$";
        std::cin >> Money;
    } while (!ValidInput(Money && Money > 0 && (Action == "withdraw" ? Money <= CurrentAmount : true)));
    return Money;
}

double Amount(double Money) {
    std::cout << '\n' << "Your balance";
    std::cout << '\n' << "R$"<< std::setprecision(2) << std::fixed << Money << '\n';
    return 0;
}

int main() {
    double CurrentAmount = 0;
    int MenuChoice;
    std::string Option;
    do {
        MenuChoice = BankMenu();
        switch(MenuChoice){
            case 1:
                Amount(CurrentAmount);
                break;
            case 2:
                CurrentAmount += Money("deposit", CurrentAmount);
                break;
            case 3:
                CurrentAmount -= Money("withdraw" , CurrentAmount);
                break;
            case 4:
                break;
        }
    } while(MenuChoice != 4);
    
}