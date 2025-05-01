class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we can binary search for the correct row
        // then binsearch on the row to find target
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        int rl = 0;
        int rr = num_rows - 1;

        while (rl <= rr) {
            int rm = (rl + rr) / 2;
            if (matrix[rm][0] > target) {
                rr = rm - 1;
            } else if (matrix[rm][num_cols - 1] < target) {
                rl = rm + 1;
            } else {
                break;
            }
        }
        int row = (rl + rr) / 2; // this is the correct row
        int cl = 0;
        int cr = num_cols - 1;
        while (cl <= cr) {
            int cm = (cl + cr) / 2;
            if (matrix[row][cm] > target) {
                cr = cm - 1;
            } else if (matrix[row][cm] < target) {
                cl = cm + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
