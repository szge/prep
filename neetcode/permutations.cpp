class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& subset, vector<bool>& pick, vector<vector<int>>& sol) {
        if (subset.size() == nums.size()) {
            sol.push_back(subset);
            return;
        }
        for (int i = 0; i < pick.size(); i++) {
            if (pick[i] == false) {
                pick[i] = true;
                subset.push_back(nums[i]);
                dfs(nums, subset, pick, sol);
                pick[i] = false;
                subset.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> subset;
        vector<bool> pick(nums.size(), false);
        dfs(nums, subset, pick, sol);
        return sol;
    }
};
