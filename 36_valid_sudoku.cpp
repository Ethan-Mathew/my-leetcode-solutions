class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Iterate over rows
        for (int n{}; n < board.size(); n++) {
            std::unordered_set<char> rowSeen;
            for (int m{}; m < board[n].size(); m++) {
                if (rowSeen.find(board[n][m]) == rowSeen.end()) {
                    if (std::isdigit(board[n][m])) {
                        rowSeen.insert(board[n][m]);
                    }
                } else {
                    return false;
                }
            }
        }

        // Iterate down columns
        for (int m{}; m < board[0].size(); m++) {
            std::unordered_set<char> columnSeen;
            for (int n{}; n < board.size(); n++) {
                if (columnSeen.find(board[n][m]) == columnSeen.end()) {
                    if (std::isdigit(board[n][m])) {
                        columnSeen.insert(board[n][m]);
                    }
                } else {
                    return false;
                }
            }
        }

        // Examine 3 * 3 squares
        for (int a{}; a < 9; a += 3) {
            for (int b{}; b < 9; b += 3) {
                std::unordered_set<char> squareSeen;
                for (int i{}; i < 3; i++) {
                    for (int j{}; j < 3; j++) {
                        if (squareSeen.find(board[a + i][b + j]) == squareSeen.end()) {
                            if (std::isdigit(board[a + i][b + j])) {
                                squareSeen.insert(board[a + i][b + j]);
                            }
                        } else {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};