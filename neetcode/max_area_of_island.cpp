#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
    // idea: similar to number of islands, use a disjoint-set to track islands;
    // maintain an island_sizes parallel to parent
private:
    std::vector<int> parent;
    std::vector<int> island_sizes;

    int square_to_hash(int cols, int x, int y) {
        return y * cols + x;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int i, int j) {
        int iroot = find(i);
        int jroot = find(j);
        if (iroot == jroot) return;
        if (island_sizes[iroot] < island_sizes[jroot]) {
            parent[iroot] = jroot;
            island_sizes[jroot] += island_sizes[iroot];
        } else {
            parent[jroot] = iroot;
            island_sizes[iroot] += island_sizes[jroot];
        }
    }

public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int cols = grid[0].size();
        int rows = grid.size();
        parent.resize(rows * cols);
        island_sizes.resize(rows * cols);
        std::unordered_map<int, int> island_areas;
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                int h = square_to_hash(cols, x, y);
                if (grid[y][x] == 1) {
                    parent[h] = h; // init disjoint-set
                    island_sizes[h] = 1;
                    if (x > 0 && grid[y][x - 1] == 1) {
                        // join with left
                        int h2 = square_to_hash(cols, x - 1, y);
                        unite(h, h2);
                    }
                    if (y > 0 && grid[y - 1][x] == 1) {
                        // join with up
                        int h2 = square_to_hash(cols, x, y - 1);
                        unite(h, h2);
                    }
                }
            }
        }
        return *std::max_element(island_sizes.begin(), island_sizes.end());
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid {
        {0,1,1,0,1},
        {1,0,1,0,1},
        {0,1,1,0,1},
        {0,1,0,0,1}
    };

    std::cout << solution.maxAreaOfIsland(grid) << std::endl;
}