class Solution {
    // idea 1: I could convert candidates into an unordered map {candidate, freq}

private:
    void dfs(vector<int>& candidates, int target, int curr, vector<int>& subset, vector<vector<int>>& sol) {
        if (target <= 0) {
            if (target == 0) sol.push_back(subset);
            return;
        }
        if (candidates.size() == 0) return;

        for (int i = curr; i < candidates.size(); i++) {
            // only use a starting number once to avoid duplicates
            if (i > curr && candidates[i] == candidates[i - 1]) continue;
            subset.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, subset, sol);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, subset, sol);
        return sol;
    }
};
