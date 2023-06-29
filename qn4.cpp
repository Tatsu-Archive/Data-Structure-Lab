#include <iostream>
using namespace std;

void reverse(string& rev, const string& s) {
    if (s.empty()) {
        return;
    }
    
    reverse(rev, s.substr(1));
    rev += s[0];
}

int main() {
    string str, rev;
    cout << "Enter a string: ";
    cin >> str;
    reverse(rev, str);
    cout << "\nOriginal string: " << str << " | Reversed string: " << rev;
    if (str == rev) {
        cout << " (Palindrome)";
    }
    else {
        cout << " (Not a palindrome)";
    }
    return 0;
}

/*
Input: hello
Output: olleh (Not a palindrome)

Input: madam
Output: madam (Palindrome)
*/
