#include <iostream>
#include <string>
using namespace std;

// Hàm kiểm tra palindrome
bool checkIfPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    // Test case 1: "racecar"
    string test1 = "racecar";
    cout << "Checking if '" << test1 << "' is a palindrome: ";
    if (checkIfPalindrome(test1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    // Test case 2: "oceba"
    string test2 = "oceba";
    cout << "Checking if '" << test2 << "' is a palindrome: ";
    if (checkIfPalindrome(test2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
