class Solution {
public:
    // originally I did this by summing subset and comparing to target.
    // but if I actually just subtract nums[i] from target, I avoid these sums, at the cost of extra memory for target.
    void dfs(vector<int>& nums, int target, vector<int>& subset, int curr, vector<vector<int>>& sol) {
        if (target == 0) {
            sol.push_back(subset);
            return;
        }
        if (target < 0) return;
        for (int i = curr; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(nums, target - nums[i], subset, i, sol);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> subset;
        dfs(nums, target, subset, 0, sol);
        return sol;
    }
};
