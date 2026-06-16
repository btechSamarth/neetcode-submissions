class Solution {
public:
    void solve(vector<vector<int>> &grid , vector<vector<int>>& visited , int i , int j , int& count){
        if(i<0 || j <0 || i == grid.size() || j == grid[0].size()){
            return;
        }

        if(grid[i][j] == 0) return;

        visited[i][j] = 1;
        count++;

        if(i-1 >= 0 && !visited[i-1][j]){solve(grid , visited , i-1 , j ,count);}
        if(i+1 < grid.size() && !visited[i+1][j]){solve(grid , visited , i+1 , j , count);}
        if(j-1 >= 0 && !visited[i][j-1]){solve(grid , visited , i , j-1 , count);}
        if(j+1 < grid[0].size() && !visited[i][j+1]){solve(grid , visited , i , j+1, count);}

        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int ans = 0;
        vector<vector<int>> visited(grid.size() , vector<int>(grid[0].size() , 0));
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    solve(grid , visited , i , j , count);
                    ans = max(ans , count);
                    count = 0;
                }
            }
        }
        return ans;
    }
};
