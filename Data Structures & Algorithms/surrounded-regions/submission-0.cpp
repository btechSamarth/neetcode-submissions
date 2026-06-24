class Solution {
public:
    void solve2(vector<vector<char>>& board , vector<vector<int>>& visited , int i , int j){
        int n = board.size() ; int m = board[0].size();
        
        visited[i][j] = 1;

        vector<int> dir = {i-1 , i+1};
        vector<int> dir2 = {j-1 , j+1};

        for(auto p : dir){
            if(p<0 || j < 0 || p >= n || j >= m){
                continue;
            }
            if(visited[p][j] == 0 && board[p][j] == 'O') solve2(board , visited , p , j);
        }

        for(auto q : dir2){
            if(i<0 || q < 0 || i >= n || q >= m){
                continue;
            }   
            if(visited[i][q] == 0 && board[i][q] == 'O') solve2(board , visited , i , q);
        }

        return;

    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visited(board.size() , vector<int>(board[0].size() , 0));
        int m = board[0].size()-1; int n = board.size()-1;
        vector<int> dir = {0 , m};

        for(auto j : dir){
            for(int i = 0 ; i < board.size() ; i++){
                if(visited[i][j] == 0 && board[i][j] == 'O'){
                    solve2(board , visited , i , j);
                }
            }
        }

        dir[1] = n;

        for(auto i : dir){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(visited[i][j] == 0 && board[i][j] == 'O'){
                    solve2(board , visited , i , j);
                }
            }
        }

        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(visited[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
