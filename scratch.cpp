#include <vector>
#include <numeric>
#include <iostream>

class Solution {
private:
    void dfs(std::vector<int>& nums, int& target, std::vector<int>& subset, std::vector<std::vector<int>>& sol) {
        int sum = std::accumulate(subset.begin(), subset.end(), 0);
        if (sum == target) {
            std::cout << "found a good subset" << std::endl;
            sol.push_back(subset);
            return;
        }
        if (sum > target) return;
        for (int num : nums) {
            subset.push_back(num);
            dfs(nums, target, subset, sol);
            subset.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> sol;
        std::vector<int> subset;
        dfs(nums, target, subset, sol);
        return sol;
    }
};

int main() {
    Solution solver;
    std::vector<int> nums { 2,5,6,9 };
    auto solution = solver.combinationSum(nums, 9);
}