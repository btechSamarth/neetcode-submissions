class Solution {
public:

    bool solve(vector<vector<char>>& board , string word , int i , int j , string temp , vector<vector<int>>& visited){
        if(temp == word){
            return true;
        }
        if(temp.size() >= word.size()){
            return false;
        }
        if(i>= board.size() || j >= board[0].size() || i < 0 || j < 0){
            return false;
        }
     
        if(visited[i][j]){
            return false;
        }
        visited[i][j] = 1;
            bool down = solve(board , word , i , j+1 , temp +  board[i][j] , visited);
            if(down){
                return down;
            }
            bool right = solve(board , word , i+1 , j , temp +  board[i][j] , visited);
            if(right){
                return right;
            }
            bool left = solve(board , word , i , j-1 , temp + board[i][j] , visited);
            if(left){
                return left;
            }
            bool up = solve(board , word , i-1 , j , temp + board[i][j] , visited);
            if(up){
                return up;
            } 
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size() , vector<int>(board[0].size() , 0));
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == word[0]){
                    string temp = "";
                    bool flag = solve(board , word , i , j , temp , visited);
                    if(flag){
                        return flag;
                    }
                }
            }
        }

        return false;
    }
};
