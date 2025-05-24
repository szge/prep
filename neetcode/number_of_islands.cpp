class Solution {
    // idea 1: we can use union-find with the hash of the square

private:
    vector<int> parent;

    int square_to_hash(vector<vector<char>>& grid, int x, int y) {
        int row_size = grid[0].size();
        return row_size * y + x;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        // return find(parent[i]);
        // path compression version for efficiency:
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int i, int j) {
        int irep = find(i);
        int jrep = find(j);
        if (irep != jrep) parent[jrep] = irep;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cols = grid[0].size();
        int rows = grid.size();
        parent.resize(rows * cols);
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                int h = square_to_hash(grid, x, y);
                if (grid[y][x] == '1') {
                    // init UnionFind by adding each land square to parent
                    parent[h] = h;
                    if (x > 0 && grid[y][x - 1] == '1') {
                        // join with left
                        int h2 = square_to_hash(grid, x - 1, y);
                        unite(h, h2);
                    }
                    if (y > 0 && grid[y - 1][x] == '1') {
                        // join with up
                        int h2 = square_to_hash(grid, x, y - 1);
                        unite(h, h2);
                    }
                }
            }
        }

        unordered_set<int> roots;
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (grid[y][x] == '1') {
                    int h = square_to_hash(grid, x, y);
                    roots.insert(find(h));
                }
            }
        }
        return roots.size();
    }
};
