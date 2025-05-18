#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<std::pair<int, int>> valid_squares(std::vector<std::vector<bool>>& board, int& n) {
        std::vector<std::pair<int, int>> vs;
        std::vector<std::vector<bool>> taken(n, std::vector<bool>(n, false));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (board[y][x]) {
                    int diff = abs(x - y);
                    for (int b_i = 0; b_i < n; b_i++) {
                        taken[y][b_i] = true; // set row
                        taken[b_i][x] = true; // set col
                        if (b_i <= x + y) {
                            // the first diagonal is when x + y is the same as the current queen
                            taken[b_i][x + y - b_i] = true;
                        }
                        if (b_i < n - diff) {
                            // the second diagonal is when x - y is the same as the current queen
                            if (x - y >= 0) {
                                taken[b_i][diff + b_i] = true;
                            } else {
                                taken[diff + b_i][b_i] = true;
                            }
                        }
                    }
                }
            }
        }
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (!taken[y][x]) {
                    vs.emplace_back(x, y);
                }
            }
        }
        return vs;
    }

    int count_queens(std::vector<std::vector<bool>>& board) {
        int c = 0;
        for (auto row : board) {
            for (auto square : row) {
                if (square) c++;
            }
        }
        return c;
    }

    void dfs(std::vector<std::vector<bool>>& board, int& n, std::vector<std::vector<std::string>>& sols) {
        int num_queens = count_queens(board);
        if (num_queens == n) {  // base case
            std::vector<std::string> sol;
            for (auto row : board) {
                std::string r;
                for (auto square : row) {
                    r.push_back((square) ? 'Q' : '.');
                }
                sol.push_back(r);
            }
            sols.push_back(sol);
            return;
        }

        std::vector<std::pair<int, int>> vs = valid_squares(board, n);
        for (auto s : vs) {
            int& x = s.first, y = s.second;
            board[y][x] = true;
            dfs(board, n, sols);
            board[y][x] = false;
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<bool>> board(n, std::vector<bool>(n, false));
        std::vector<std::vector<std::string>> sols;
        dfs(board, n, sols);
        return sols;
    }
};


int main() {
    int n = 4;
    std::vector<std::vector<bool>> board(n, std::vector<bool>(n, false));
    board[1][1] = true;
    Solution solution;
    int num_queens = solution.count_queens(board);
    std::cout << "Number of queens on the board: " << num_queens << std::endl;
    auto vs = solution.valid_squares(board, n);
    std::cout << "Valid queen positions:" << std::endl;
    for (auto v : vs) std::cout << v.first << ", " << v.second << std::endl;
    auto sols = solution.solveNQueens(n);
    for (auto sol : sols) {
        std::cout << "Solution:" << std::endl;
        for (auto row : sol) std::cout << row << std::endl;
    }
}
