/* Given a string s containing just the characters '(', ')', '[', ']', '{', and '}'. Check if the input string is valid based on following rules:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.*/
#include <iostream>
#include <stack>
using namespace std;
//---START---
bool isValidParentheses (string str){
    stack<char> s;
    for (char c: str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else {
            if (s.empty()) {
                return false;
            }
            if (c == ')' && s.top() == '(') {
                s.pop();
            }
            else if (c == ']' && s.top() == '[') {
                s.pop();
            }
            else if (c == '}' && s.top() == '{') {
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    return s.empty();
}
//---END---
int main()
{
  cout << isValidParentheses("[]");
  return 0;
}
