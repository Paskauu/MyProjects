#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int SelectedValue;
    int Result;
    Result = 1;

    cout << "Enter the limit of the array: ";
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << "º value: ";
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        SelectedValue = a[i];
        Result *= SelectedValue;
    }
    cout << "Result: " << Result;
}