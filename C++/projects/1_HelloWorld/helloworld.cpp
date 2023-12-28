#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    vector<string> msg {"Hello","C++","World","From","VS Code","and the C++ extension n!"};

    cout << endl;

    for (const string& word : msg)
    {
        cout << word << "\n";
    }
    cout << endl;
}