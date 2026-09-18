class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(board[i][j] == 'O'){
                        q.push({i, j});
                        board[i][j] = 'T';
                    }
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty()){
            auto[x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int r = dx[i] + x;
                int c = dy[i] + y;

                if(r < n && r >= 0 && c < m && c >= 0 && board[r][c] == 'O'){
                    q.push({r, c});
                    board[r][c] = 'T';
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};