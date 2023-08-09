#include <iostream>
using namespace std;

int binary(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 2) + 10 * binary(n / 2);
}

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << "Binary equivalent: " << binary(n);
    return 0;
}

/*
Input: 10
Output: 1010
*/