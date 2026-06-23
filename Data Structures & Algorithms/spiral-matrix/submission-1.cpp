class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int xsg = 0;
        int xeg = matrix.size()-1;
        int ysg = 0;
        int yeg = matrix[0].size()-1;
        vector<int>ans;

        while(xsg <= xeg && ysg <= yeg){
            vector<int>temp;
            if(ysg > yeg){
                break;
            }
            for(int j = ysg ; j <= yeg ; j++ ){
                temp.push_back(matrix[xsg][j]);
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
            xsg++;
            temp.clear();

            if(xsg > xeg){
                break;
            }

            for(int i = xsg ; i <= xeg ; i++){
                temp.push_back(matrix[i][yeg]);
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
            yeg--;
            temp.clear();

            if(ysg > yeg){
                break;
            }
            for(int j = ysg ; j <= yeg ; j++){
                temp.push_back(matrix[xeg][j]);
            }
            reverse(temp.begin() , temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
            xeg--;
            temp.clear();
            if(xsg > xeg){
                break;
            }
            for(int i = xsg ; i <= xeg ; i++){
                temp.push_back(matrix[i][ysg]);
            }
            reverse(temp.begin() , temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
            ysg++;
            temp.clear();
        }

        
        return ans;
    }
};
