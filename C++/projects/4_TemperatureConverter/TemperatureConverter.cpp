#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

int main() {
    double Temperature;
    double ConvertedTemperature;
    std::string Convert;
    std::string To;
    std::string Command;
    std::string ValidConverts = "CFK";
    std::string ValidCommands = "YN";

    do {
        do {
            std::cin.clear();
            std::cout << "\n\t-Convert-\n->Celsius (C)\n->Fahrenheit (F)\n->Kelvin (K)\n";
            std::cin >> std::ws >> Convert;
            std::transform(Convert.begin(), Convert.end(), Convert.begin(), ::toupper);
            if(ValidConverts.find(Convert) != std::string::npos) {
                break;
            } else {
                std::cin.clear();
                std::cout << "\nInvalid Input!\nTry again.\n\n";
            }
        }
        while(true);

        do {
            std::cin.clear();
            std::cout << "\nValue to be converted:";
            std::cin >> Temperature;
            if (Temperature) {
                break;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nInvalid Input!\nTry again.\n";
            }
        }
        while(true);

        do {
            std::cin.clear();
            std::cout << "\n\t-To-\n->Celcius (C)\n->Fahrenheit (F)\n->Kelvin (K)\n";
            std::cin >> To;
            std::transform(To.begin(), To.end(), To.begin(), ::toupper);
            if (ValidConverts.find(To) != std::string::npos && Convert != To) {
                break;
            } else {
                std::cin.clear();
                std::cout << "\nInvalid Input!\nTry again.\n";
            }
        }
        while(true);

        if(Convert == "C") {
            if (To == "F") {
                ConvertedTemperature = (Temperature * 9/5) + 32;
                std::cout << "\n" << Temperature << "°C -> " << ConvertedTemperature << "°F";
            } else if (To == "K") {
                ConvertedTemperature = Temperature + 273.15;
                std::cout << "\n" << Temperature << "°C -> " << ConvertedTemperature << "K";
            }
        } else if (Convert == "F") {
            if (To == "C") {
                ConvertedTemperature = (Temperature - 32) * 5/9;
                std::cout << "\n" << Temperature << "°F -> " << ConvertedTemperature << "°C";
            } else if (To == "K") {
                ConvertedTemperature = (Temperature - 32) * 5/9 + 273.15;
                std::cout << "\n" << Temperature << "°F -> " << ConvertedTemperature << "K";
            }
        } else if (Convert == "K") {
            if (To == "C") {
                ConvertedTemperature = Temperature - 273.15;
                std::cout << "\n" << Temperature << "K -> " << ConvertedTemperature << "°C";
            } else if (To == "F") {
                ConvertedTemperature = (Temperature - 273.15) * 9/5 + 32 ;
                std::cout << "\n" << Temperature << "K -> " << ConvertedTemperature << "°F";
            }
        }

        do {
            std::cin.clear();
            std::cout << "\nConvert other value? [Y] [N] ";
            std::cin >> Command;
            std::transform(Command.begin(), Command.end(), Command.begin(), ::toupper);
            if (ValidCommands.find(Command) != std::string::npos) {
                break;
            } else {
                std::cin.clear();
                std::cout << "\n\nInvalid Input!\nTry again.\n";
            }
        }
        while(true);

        if (Command == "N") {
            std::cout << "\nBye!";
            break;
        }
    }
    while(true);
}