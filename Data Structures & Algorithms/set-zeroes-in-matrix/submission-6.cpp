class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool hor = false; bool vert = false;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == 0){
                    if(i == 0 && j== 0) {
                        hor = true; vert = true;
                    } 
                    else if(i == 0) hor = true;
                    else if(j == 0) vert = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        vector<int> temp(matrix[0].size() , 0);

        for(int i = 1 ; i < matrix.size() ; i++){
            if(matrix[i][0] == 0){
                matrix[i] = temp;
            }
        }

        for(int j = 1 ; j < matrix[0].size() ; j++){
            if(matrix[0][j] == 0){
                for(int i = 1 ; i < matrix.size() ; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            if(hor) matrix[0] = temp;
            if(vert){
                for(int i = 1 ; i < matrix.size() ; i++){
                    matrix[i][0] = 0;
                }
            }
        }

        return;
    }
};
