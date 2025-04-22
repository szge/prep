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
        // first attempt
        // time o(n^2) due to substring creation and find
        // int lengthOfLongestSubstring(string s) {
        //     int l = 0;
        //     int max_len = 0;
        //     for (int r = 0; r < s.size(); r++) {
        //         int len = r - l + 1;
        //         // create a string from l to r, but exclude s[r]
        //         string substring = s.substr(l, len - 1);
        //         std::size_t found = substring.find(s[r]);
        //         if (found == std::string::npos) {
        //             // there's no duplicate, so we can include s[r]
        //             max_len = max(max_len, len);
        //         } else {
        //             // there's a duplicate
        //             // remove everything up to and including the first instance of s[r]
        //             l += found + 1;
        //         }
        //     }
        //     return max_len;
        // }
    
        // second attempt
        // basically my previous solution
        // but instead of using an actual substring
        // I can use a set to represent it
        // so I can check for s[r] in o(1)
        int lengthOfLongestSubstring(string s) {
            int l = 0;
            int max_len = 0;
            unordered_set<char> curr_substr_set;
    
            for (int r = 0; r < s.size(); r++) {
                // remove all letters up until s[r] from the substring
                while (curr_substr_set.count(s[r]) > 0) {
                    curr_substr_set.erase(s[l]);
                    l++;
                }
                curr_substr_set.insert(s[r]);
                int substr_len = r - l + 1;
                max_len = max(max_len, substr_len);
            }
            return max_len;
        }
    };
    