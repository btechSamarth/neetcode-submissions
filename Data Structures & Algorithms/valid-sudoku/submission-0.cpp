class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        //rows
        for(int i = 0 ; i < n ; i++){
            vector<int> check(board.size()+1 , -1);
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                else if(check[board[i][j] - '0'] == 1){
                    return false;
                }
                else{
                    check[board[i][j] - '0'] = 1;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            vector<int> check(board.size()+1 , -1);
            for(int j = 0 ; j < n ; j++){
                if(board[j][i] == '.'){
                    continue;
                }
                else if(check[board[j][i] - '0'] == 1){
                    return false;
                }
                else{
                    check[board[j][i] - '0'] = 1;
                }
            }
        }

        for(int i = 0 ; i < n ; i+=3){
            for(int j = 0 ; j < n ; j+=3){
                int size = int(sqrt(n));
                vector<int> check(board.size()+1 , -1);
                for(int k = 0 ; k < n ; k++){
                    int x = size*((i)/size) + (k/size);          //star formula
                    int y = size*((j)/size) + (k%size);
                    if(board[x][y] == '.'){
                        continue;
                    }
                    else if(check[board[x][y] - '0'] == 1 ){
                        return false;
                    }
                    else{
                        check[board[x][y] - '0'] = 1;
                    }
                }
            }   
        }
        return true;
    }
};
