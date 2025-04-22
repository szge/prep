#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            std::stack<int> rpn_stack;
            for (string s : tokens) {
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
    