#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parenthesis;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parenthesis.push(c);
                std::cout << c << std::endl;
            } else if (!parenthesis.empty()) {
                std::cout << "reading " << c << " top " << parenthesis.top() << std::endl;
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
