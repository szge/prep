class Solution {
public:
    int hoursToEat(vector<int>& piles, int k) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += ceil((double) piles[i] / k);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // information we can use: each pile is independent;
        // the minimum number of hours is the number of piles;
        // given k, num hours required to eat pile i is ceil(piles[i] / k)
        // crappy brute force is to test different values of k.
        // we can maybe guess k in an optimal way doing binsearch
        // 1 <= k <= max pile size
        int max_pile_size = piles[0];
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > max_pile_size) max_pile_size = piles[i];
        }
        int l = 1;
        int r = max_pile_size;
        while (l <= r) {
            int m = (l + r) / 2;
            if (hoursToEat(piles, m) > h) {
                l = m + 1; // we need a larger k value since it takes too long to eat
            } else {
                r = m - 1; // we can try smaller values for k
            }
        }
        return l;
    }
};
