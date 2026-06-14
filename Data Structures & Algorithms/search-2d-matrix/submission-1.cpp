class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int num = n-1;

        bool flag = false;
        int idx;
        for(int j = 0 ; j < matrix.size() ; j++){
            if(matrix[j][n-1] >= target){
                idx = j;
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
        else{
            int start = 0;
            int end = n-1;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(matrix[idx][mid] == target){
                    return true;
                }
                else if(matrix[idx][mid] > target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            return false;
        }
        return false;
    }
};
