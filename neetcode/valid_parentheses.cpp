class Solution {
    public:
        bool isValid(string s) {
            std::stack<char> stack;
            std::unordered_map<char, char> close_to_open_map = {
                {')', '('},
                {'}', '{'},
                {']', '['}
            };
    
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if ((c == '(') || (c == '{') || (c == '[')) {
                    stack.push(c);
                } else {
                    if (stack.empty() || stack.top() != close_to_open_map[c]) {
                        return false;
                    }
                    stack.pop();
                }
            }
    
            return stack.empty();
        }
    };
    