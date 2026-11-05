#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parenthesis;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parenthesis.push(c);
            } else if (!parenthesis.empty()) {
                char top = parenthesis.top();
                if (top == '(' && c != ')') {
                    return false;
                } else if (top == '[' && c != ']') {
                    return false;
                } else if (top == '{' && c != '}'){
                    return false;
                } else {
                    parenthesis.pop();
                }
            } else {
                return false;
            }
        }
        if (parenthesis.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
