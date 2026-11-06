#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;
        
        for (auto token : tokens) {
            if (token == "+") {
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();
                numbers.push(second + first);
            } else if (token == "-") {
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();
                numbers.push(second - first);
            } else if (token == "*") {
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();
                numbers.push(second * first);
            } else if (token == "/"){
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();
                numbers.push(second / first);
            } else {
                numbers.push(std::stoi(token));
            }
        }

        return numbers.top();
    }
};
