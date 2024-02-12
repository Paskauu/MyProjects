#include <iostream>
// Address in a memory
int Swap(std::string &Father, std::string &Mother) {
    std::string temp;
    temp = Father;
    Father = Mother;
    Mother = temp;
    return 0;
}

int main() {
    std::string Father  = "Luciano";
    std::string Mother  = "Alessandra";

    std::cout << "Address of Father: " << &Father << '\n';
    std::cout << "Address of Mother: " << &Mother << '\n';
    std::cout << "Father: " << Father << '\n';
    std::cout << "Mother: " << Mother << '\n';

    // Swap Functions using reference
    // U need to pass the address in the funcion parameter
    Swap(Father,Mother);
    std::cout << '\n' << "Swap Functions using reference"  << '\n';
    std::cout << "Father: " << Father << '\n';
    std::cout << "Mother: " << Mother << '\n';
    

    return 0;
}