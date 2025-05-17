class KthLargest {
    // private:
    //     multiset<int> k_largest;
    //     int max_size;

    // public:
    // ideally soln has o(mlogk) time and o(k) space, where m is the number of adds
    // idea 1: use a set to store the top k elements as the get added. this satisfies complexity
    // KthLargest(int k, vector<int>& nums) {
    //     max_size = k;
    //     for (int i = 0; i < nums.size(); i++) {
    //         add(nums[i]);
    //     }
    // }

    // int add(int val) {
    //     if (k_largest.size() <= max_size || val > *(k_largest.begin())) {
    //         k_largest.insert(val);
    //         if (k_largest.size() > max_size) k_largest.erase(k_largest.begin());
    //     }
    //     return *(k_largest.begin());
    // }

    // idea 2: min-heap
    // a min-heap is (1) complete bintree (2) minheap property: root node is the smallest in tree (3) children are minheaps
    // TIL that set/multiset and heap are both okay but multiset is slower due to o(nlogn) initial construction from array
private:
    priority_queue<int, vector<int>, greater<int>> top_k;
    int max_size;

public:
    KthLargest(int k, vector<int>& nums) {
        max_size = k;
        for (int num : nums) add(num);
    }

    int add(int val) {
        top_k.push(val);
        while (top_k.size() > max_size) top_k.pop();
        return top_k.top();
    }
};
