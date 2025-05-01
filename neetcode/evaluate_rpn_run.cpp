#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> rpn_stack;
        for (std::string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int second = rpn_stack.top();
                rpn_stack.pop();
                int first = rpn_stack.top();
                rpn_stack.pop();
                if (s == "+") {
                    rpn_stack.push(first + second);
                } else if (s == "-") {
                    rpn_stack.push(first - second);
                } else if (s == "*") {
                    rpn_stack.push(first * second);
                } else {
                    rpn_stack.push(first / second);
                }
            } else {
                rpn_stack.push(std::stoi(s));
            }
        }
        return rpn_stack.top();
    }
};

int main() {
    // Example test cases
    std::vector<std::vector<std::string>> testCases = {
        {"2", "1", "+", "3", "*"},          // ((2 + 1) * 3) = 9
        {"4", "13", "5", "/", "+"},         // (4 + (13 / 5)) = 6
        {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"} // Complex example
    };

    Solution solution;

    for (const auto& tokens : testCases) {
        std::cout << "Input: [";
        for (size_t i = 0; i < tokens.size(); ++i) {
            std::cout << "\"" << tokens[i] << "\"";
            if (i < tokens.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;

        int result = solution.evalRPN(tokens);
        std::cout << "Output: " << result << std::endl << std::endl;
    }

    // Optional: Allow user to input their own RPN expression
    std::cout << "Enter your own RPN expression (space-separated tokens, empty line to quit):" << std::endl;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        std::vector<std::string> userTokens;
        std::string token;

        // Parse input line into tokens
        size_t pos = 0;
        while ((pos = line.find(' ')) != std::string::npos) {
            token = line.substr(0, pos);
            userTokens.push_back(token);
            line.erase(0, pos + 1);
        }
        if (!line.empty()) {
            userTokens.push_back(line);
        }

        try {
            int result = solution.evalRPN(userTokens);
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error evaluating expression: " << e.what() << std::endl;
        }

        std::cout << "Enter another expression (empty line to quit):" << std::endl;
    }

    return 0;
}