#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // int maxArea(vector<int>& heights) {
        //     // brute force time o(n^2)
        //     int maxWater = 0;
        //     int n = heights.size();
        //     for (int i = 0; i < n; i++) {
        //         for (int j = i + 1; j < n; j++) {
        //             int width = j - i;
        //             int height = min(heights[i], heights[j]);
        //             int area = width * height;
        //             maxWater = max(maxWater, area);
        //         }
        //     }
        //     return maxWater;
        // }
    
        // things I know:
        // width = j - i
        // height = min(heights[i], heights[j])
        // area = width * height
    
        // idea 1: "pouring water" from the top??
        // idea 2: could iterate over the widths (container widths = 1, 2, ...)
        // this would be o(n^2) but maybe there's a clever way to do it
        // idea 3: two pointer alg... but how to choose which side to update?
    
        int maxArea(vector<int>& heights) {
            int l = 0;
            int r = heights.size() - 1;
            int maxArea = 0;
    
            while (l < r) {
                int width = r - l;
                int height = min(heights[l], heights[r]);
                int area = width * height;
                maxArea = max(maxArea, area);
    
                if (heights[l] <= heights[r]) {
                    l++;
                } else {
                    r--;
                }
            }
    
            return maxArea;
        }
    };
    