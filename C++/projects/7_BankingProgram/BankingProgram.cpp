#include <iostream>
#include <cmath>

double VerifyNumberInput(double Num, std::string Frase) {
    do {
        std::cout << Frase;
        std::cin >> Num;
        if(Num){
            return Num;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input. Try again!\n";
        }
    } while(true);
}

double DepositMoney() {
    double Money = 0;
    Money = VerifyNumberInput(Money,"How many do you want o deposit? ");
    return Money;
}

int BankMenu() {
    int Choice;
    Choice = VerifyNumberInput(Choice,"a");
    return Choice;
}

int main() {
    double CurrentAcount = 0;
    CurrentAcount += BankMenu();
    std::cout << CurrentAcount;
}