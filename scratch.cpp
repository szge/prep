#include <vector>
#include <iostream>

class Solution {
    // idea 1: I could convert candidates into an unordered map {candidate, freq}

private:
    void dfs(std::vector<int>& candidates, int target, int curr, std::vector<int>& subset, std::vector<std::vector<int>>& sol) {
        if (target <= 0) {
            if (target == 0) sol.push_back(subset);
            return;
        }
        if (candidates.size() == 0) return;

        for (int i = curr; i < candidates.size(); i++) {
            if (i > curr && candidates[i] == candidates[i - 1]) continue;
            subset.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, subset, sol);
            subset.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> sol;
        std::vector<int> subset;
        std::sort(candidates.begin(), candidates.end());
        // for (int c : candidates) std::cout << c << " ";
        // std::cout << std::endl;
        dfs(candidates, target, 0, subset, sol);
        return sol;
    }
};

int main() {
    std::vector<int> candidates {9,2,2,4,6,1,5};
    Solution solution;
    auto sols = solution.combinationSum2(candidates, 8);
    for (auto sol : sols) {
        for (int i : sol) std::cout << i << " ";
        std::cout << std::endl;
    }
}
