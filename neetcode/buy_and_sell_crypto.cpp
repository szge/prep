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
        // int maxProfit(vector<int>& prices) {
        //     vector<int> min_buy(prices.size());
        //     int curr_min = prices[0];
        //     for (int i = 0; i < prices.size(); i++) {
        //         curr_min = min(curr_min, prices[i]);
        //         min_buy[i] = curr_min;
        //     }
        //     int max_profit = 0;
        //     for (int i = 0; i < prices.size(); i++) {
        //         int curr_profit = prices[i] - min_buy[i]; // sell now price
        //         max_profit = max(max_profit, curr_profit);
        //     }
        //     return max_profit;
        // }
    
        // one loop
        int maxProfit(vector<int>& prices) {
            int max_profit = 0;
            int min_buy = prices[0];
    
            for (int i = 0; i < prices.size(); i++) {
                int sell = prices[i];
                int curr_profit = sell - min_buy;
                max_profit = max(max_profit, curr_profit);
                min_buy = min(min_buy, sell);
            }
            return max_profit;
        }
    
    };
    