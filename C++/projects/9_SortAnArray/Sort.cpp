#include <iostream>

int Sort(int Array[], int ArraySize) {
    for (int i = 0; i < ArraySize - 1; i++ ) {
        for(int j = 0; j < ArraySize - i - 1; j++) {
            if(Array[j] > Array[j + 1]) {
               int TempValue = Array[j];
               Array[j] = Array[j + 1];
               Array[j + 1] = TempValue;  
            }
        }
    }
    return 0;
}

int main() {
    int Array[] = {10,5,4,6,7,8,1,2,9,3};
    int ArraySize = sizeof(Array)/sizeof(Array[0]);

    Sort(Array,ArraySize);

    for(int Num : Array) {
        std::cout << Num << " ";
    }

    return 0;
} 


