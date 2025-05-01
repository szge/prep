#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> temp_stack; // stores pairs (temp, idx)
        std::vector<int> sol(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            int curr_temp = temperatures[i];
            std::pair<int, int> curr_pair(curr_temp, i);
            while (temp_stack.size() > 0 && temp_stack.top().first < curr_temp) {
                int prev_temp = temp_stack.top().first;
                int prev_idx = temp_stack.top().second;
                sol[prev_idx] = i - prev_idx;
                temp_stack.pop();
            }
            temp_stack.push(curr_pair);
        }
        return sol;
    }
};
