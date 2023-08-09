#include <iostream>
using namespace std;

void reverse(const string& s) {
    if (s.empty()) {
        return;
    }
    
    reverse(s.substr(1));
    cout << s[0];
    return;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    reverse(str);
    cout << endl;
    return 0;
}


/*
Input: hello
Output: olleh
*/