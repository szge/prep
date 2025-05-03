class Solution {
public:
    int findMin(vector<int> &nums) {
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
        return nums[l];
    }
};
