class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> num_q;
        for (int num : nums) {
            num_q.push(num);
            if (num_q.size() > k) num_q.pop();
        }
        return num_q.top();
    }
};
