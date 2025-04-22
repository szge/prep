#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class MinStack {
    public:
        std::stack<int> baseStack;
        std::stack<int> minStack;
    
        MinStack() {
    
        }
        
        void push(int val) {
            baseStack.push(val);
            if (minStack.size() == 0 || minStack.top() >= val) {
                minStack.push(val);
            }
        }
        
        void pop() {
            int curr = baseStack.top();
            baseStack.pop();
            if (curr == minStack.top()) {
                minStack.pop();
            }
        }
        
        int top() {
            return baseStack.top();
        }
        
        int getMin() {
            return minStack.top();
        }
    };
    