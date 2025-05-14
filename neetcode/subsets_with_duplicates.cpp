class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& sol, vector<int>& subsets, int curr) {
        if (curr >= nums.size()) return;
        for (int i = curr; i < nums.size(); i++) {
            if (i > curr && nums[i] == nums[i - 1]) continue;
            // add subsets including nums[i]
            subsets.push_back(nums[i]);
            sol.push_back(subsets);
            dfs(nums, sol, subsets, i + 1);
            // we don't care about subsets excluding nums[i]
            subsets.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        sol.push_back({});
        vector<int> subsets;
        dfs(nums, sol, subsets, 0);
        return sol;
    }
};
