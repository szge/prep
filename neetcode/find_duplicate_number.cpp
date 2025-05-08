class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // idea 1: easy solution is to use an unordered_set to check for duplicates.
        // unordered_set<int> num_set;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (num_set.count(nums[i]) == 0) {
        //         num_set.insert(nums[i]);
        //     } else {
        //         return nums[i];
        //     }
        // }
        // idea 2: we could copy the array, sort it, and check if each number is the same as the next.
        // this would take o(n) extra space and take o(nlogn) time
        // however the question wants us to find a solution that
        // (1) doesn't modify nums and (2) uses o(1) extra space.
        // we could check each pair. this would take o(n^2)time
        // it's awfully suspicious that each element of nums is in the range [1, n].
        // this leads me to believe we can use the element as an index into the array.
        // we are restricted to o(1) extra space, so we can't keep track of visited nodes.
        // I'm guessing we need to do something with cycles and fast and slow pointers.
        // int slow = 0, fast = 0;
        // while (true) {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        //     if (slow == fast) {
        //         break;
        //     }
        // }

        // int slow2 = 0;
        // while (true) {
        //     slow = nums[slow];
        //     slow2 = nums[slow2];
        //     if (slow == slow2) {
        //         return slow;
        //     }
        // }

        // okay so my thinking was correct, but the solution is unintuitive.
        // we can view the array as a linked list with a cycle.
        // the first loop does detect the cycle, but crucially, the "slow" ptr
        // is just somewhere in the cycle. We want to find the entrance to the cycle,
        // which is the duplicate number. To do this, we send a pointer to the start
        // and move slow and slow2. The point where they meet is the start of the cycle.
        // details: https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/
        // this blew my mind!!!

        // third solution: using negative values
        for (int i = 0; i < nums.size(); i++) {
            int curr_idx = abs(nums[i]) - 1;
            if (nums[curr_idx] < 0) return curr_idx + 1;
            nums[curr_idx] *= -1;
        }
    }
};
