class Solution {
public:
    void solve(vector<vector<char>> &grid , vector<vector<int>>& visited , int i , int j){
        if(i<0 || j <0 || i == grid.size() || j == grid[0].size()){
            return;
        }

        if(grid[i][j] == '0') return;

        visited[i][j] = 1;

        if(i-1 >= 0 && !visited[i-1][j])solve(grid , visited , i-1 , j);
        if(i+1 < grid.size() && !visited[i+1][j])solve(grid , visited , i+1 , j);
        if(j-1 >= 0 && !visited[i][j-1])solve(grid , visited , i , j-1);
        if(j+1 < grid[0].size() && !visited[i][j+1])solve(grid , visited , i , j+1);

        return;
    }
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        vector<vector<int>> visited(grid.size() , vector<int>(grid[0].size() , 0));
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    solve(grid , visited , i , j);
                    count++;
                }
            }
        }
        return count;
    }
};
