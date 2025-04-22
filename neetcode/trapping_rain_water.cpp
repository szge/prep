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
        // int tallestSides(vector<int>& heights, int index) {
        //     // given an index, find the tallest heights to the left and the right
        //     int left_tallest = 0;
        //     int left_tallest_idx = 0;
        //     for (i = 0; i < index - 1; i++) {
        //         curr_height = heights[i];
        //         if (curr_height > left_tallest) {
        //             left_tallest = curr_height;
        //             left_tallest_idx = i;
        //         }
        //     }
        //     int right_tallest = 0;
        //     int right_tallest_idx = 0;
        //     for (i = heights.size() - 1; i > index + 1; i--) {
        //         curr_height = heights[i];
        //         if (curr_height > right_tallest) {
        //             right_tallest = curr_height;
        //             right_tallest_idx = i;
        //         }
        //     }
        //     return [left_tallest_height, right_tallest_height];
        // }
    
        // I thought of a better idea so I'll stop the implementation of 1
        // idea 2: keep a list of tallest heights to the left and right of an index
        // by having one list for each
    
        int trap(vector<int>& height) {
            vector<int> leftHeights(height.size());
            vector<int> rightHeights(height.size());
            int tallest_left = 0;
            for (int i = 0; i < height.size(); i++) {
                tallest_left = max(tallest_left, height[i]);
                leftHeights[i] = tallest_left;
            }
            int tallest_right = 0;
            for (int i = height.size() - 1; i >= 0; i--) {
                tallest_right = max(tallest_right, height[i]);
                rightHeights[i] = tallest_right;
            }
            int total_area = 0;
            for (int i = 0; i < height.size(); i++) {
                int water_depth = min(leftHeights[i], rightHeights[i]) - height[i];
                total_area += max(water_depth, 0);
            }
            return total_area;
        }
    };
    