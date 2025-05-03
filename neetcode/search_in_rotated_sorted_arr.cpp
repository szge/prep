class Solution {
public:
    int findMinIdx(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            // we assume that the smallest element is always between l and r
            // and we enforce this assumption
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1; // smallest element is between m+1 and r
            } else {
                r = m; //smallest element is between l and m
            }
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        int min_idx = findMinIdx(nums);
        int l = 0;
        int r = nums.size() - 1;
        if (nums[min_idx] <= target && target <= nums[r]) {
            l = min_idx;
        } else {
            r = min_idx - 1;
        }
        while (l <= r) {
            int m = (l + r) / 2;
            if (target == nums[m]) return m;
            if (target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};
