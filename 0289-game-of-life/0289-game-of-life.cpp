class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> moves = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        int r = board.size(), c = board[0].size();
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int countLive = 0;
                for(auto it : moves) {
                    int nx = i + it.first;
                    int ny = j + it.second;
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c && abs(board[nx][ny]) == 1) {
                        countLive++;
                    }
                }
                if(board[i][j] == 1 && (countLive < 2 || countLive > 3)) {
                    board[i][j] = -1;
                }
                if(board[i][j] == 0 && countLive == 3) {
                    board[i][j] = 2;
                }
            }
        }
        
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(board[i][j] > 0) {
                    board[i][j] = 1;
                } 
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
};