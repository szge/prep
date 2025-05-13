class Solution {
    // public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> sol;
    //     for (int i = 0; i < (1 << n); i++) {
    //         vector<int> subset;
    //         for (int j = 0; j < n; j++) {
    //             if (i & (1 << j)) subset.push_back(nums[j]);
    //         }
    //         sol.push_back(subset);
    //     }
    //     return sol;
    // }
private:
    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        // we choose to include nums[i] in all the subsets
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res); // add all subsets with nums[i]
        subset.pop_back();
        dfs(nums, i + 1, subset, res); // add all subsets without nums[i]
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }
};
