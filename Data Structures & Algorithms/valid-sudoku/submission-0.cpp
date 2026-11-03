class Solution {
public:
    bool areRowsValid(vector<vector<char>>& board){
        for (int i = 0; i < 9; ++i){
            std::unordered_set<char> nums;
            for (int j = 0; j < 9; ++j) {
                if (nums.contains(board[i][j]) && board[i][j] != '.') {
                    return false;
                } else {
                    nums.insert(board[i][j]);
                }
            }
        }
        return true;
    }

    bool areColsValid(vector<vector<char>>& board){
        for (int i = 0; i < 9; ++i){
            std::unordered_set<char> nums;
            for (int j = 0; j < 9; ++j) {
                if (nums.contains(board[j][i]) && board[j][i] != '.') {
                    return false;
                } else {
                    nums.insert(board[j][i]);
                }
            }
        }
        return true;
    }

    bool isGridValid(vector<vector<char>>& board, int rowStart, int colStart){
        std::unordered_set<char> nums;
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j) {
                if (nums.contains(board[rowStart + i][colStart + j]) && board[rowStart + i][colStart + j] != '.') {
                    return false;
                } else {
                    nums.insert(board[rowStart + i][colStart + j]);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if (!areRowsValid(board)) {
            return false;
        }
        if (!areColsValid(board)) {
            return false;
        }
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j) {
                if (i % 3 == 0 && j % 3 == 0) {
                    if (!isGridValid(board, i , j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
