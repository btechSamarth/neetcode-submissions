class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j <= i ; j++){
                if(i != j) swap(matrix[i][j] , matrix[j][i]);
            }
        }
        int a = n/2;
        for(int j = 0 ; j < a ; j++){
            int k = n-1-j;
            for(int i = 0 ; i < n ; i++){
                swap(matrix[i][j] , matrix[i][k]);
            }
        }
    }
};
