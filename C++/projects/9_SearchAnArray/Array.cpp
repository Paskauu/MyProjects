#include <iostream>

int ShowArray(int Array[], int ArraySize){
    for(int i = 0; i < ArraySize; i++){
        std::cout << Array[i];
        if(i+1 == ArraySize) {
            std::cout << '\n';
        } else {
            std::cout << "|";
        }
    }
    return 0;
}

int SearchArray(int Array[], int ArraySize, int SearchValue) {
    for(int i = 0; i < ArraySize; i++){
        if(SearchValue == Array[i]){
            std::cout << SearchValue << " is in index " << i << '\n';
            return 0;
        } else if(i+1 == ArraySize){
            std::cout << SearchValue << " was not founded" << '\n';
            return 0;
        }
    }
    return 0;
}

int main() {
    int List[] = {1,2,3,4,5,6,7,8,9,10};
    int ArraySize = sizeof(List)/sizeof(List[0]);
    int ArrayIndex;
    int SearchValue;

    ShowArray(List,ArraySize);
    do{
        std::cout << "Value to Search for: " << '\n';
        std::cout << "-> ";
        std::cin >> SearchValue;
        SearchArray(List,ArraySize,SearchValue);
    } while(true);
    return 0;
} 

