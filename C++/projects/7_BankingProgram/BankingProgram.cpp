#include <iostream>
#include <cmath>

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

double DepositMoney() {
    double Money;
    do {
        std::cout << '\n' << "Enter the amount to deposity";
        std::cout << '\n' << "-> ";
        std::cin >> Money;
    } while (!ValidInput(Money && Money <= 4));
    return Money;
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
    } while (!ValidInput(Choice));
    return Choice;
}

int main() {
    double CurrentAmount;
    int MenuChoice;
    CurrentAmount += DepositMoney();
    std::cout << CurrentAmount;
}