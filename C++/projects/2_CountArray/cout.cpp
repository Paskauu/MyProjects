#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the max array: ";
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter digit " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Your array is \n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}