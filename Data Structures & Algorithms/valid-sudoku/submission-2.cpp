class Solution {
public:
    bool areRowsValid(const vector<vector<char>>& board){
        for (int i = 0; i < 9; ++i){
            std::unordered_set<char> nums;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (nums.contains(board[i][j])) {
                    return false;
                }

                nums.insert(board[i][j]);
            }
        }
        return true;
    }

    bool areColsValid(const vector<vector<char>>& board){
        for (int i = 0; i < 9; ++i){
            std::unordered_set<char> nums;

            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }

                if (nums.contains(board[j][i])) {
                    return false;
                }

                nums.insert(board[j][i]);
            }
        }
        return true;
    }

    bool isGridValid(const vector<vector<char>>& board, int rowStart, int colStart){
        std::unordered_set<char> nums;

        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j) {
                char value = board[rowStart + i][colStart + j];

                if (value == '.') {
                    continue;
                }

                if (nums.contains(value)) {
                    return false;
                }

                nums.insert(value);
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
        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3) {
                if (!isGridValid(board, i , j)) {
                    return false;
                }
            }
        }
        return true;
    }
};
