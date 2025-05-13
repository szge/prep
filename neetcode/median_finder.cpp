class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    // I think I've seen this problem before.
    // we want to maintain two equally sized heaps.
    // the first heap will contain the smaller half of the stream (max heap)
    // the second heap will contain the larger half of the stream (min heap)
    // make sure the first heap always has at least as many elements as the second heap.
    MedianFinder() {

    }

    void addNum(int num) {
        if (max_heap.size() + min_heap.size() == 0) {
            max_heap.push(num);
            return;
        }

        // the newly added element may be in the larger half, so we can't naively add it to the max heap (smaller half).
        double curr_median = findMedian();
        if (num <= curr_median) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        // rebalance heaps; max_heap should be 0 or 1 larger than min_heap
        if (max_heap.size() == min_heap.size() - 1) {
            int top = min_heap.top();
            min_heap.pop();
            max_heap.push(top);
        } else if (max_heap.size() == min_heap.size() + 2) {
            int top = max_heap.top();
            max_heap.pop();
            min_heap.push(top);
        }
    }

    double findMedian() {
        return (max_heap.size() == min_heap.size()) ? (((double) max_heap.top() + min_heap.top()) / 2) : max_heap.top();
    }
};
