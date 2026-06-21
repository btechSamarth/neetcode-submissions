class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        //vector<vector<int>> grid;
        int fresh = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        q.push({-1,-1});
        int time = 0;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;

            if(x != -1){
                if(x-1 >= 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    fresh--;
                    q.push({x-1,y});
                }
                if(y-1 >= 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    fresh--;
                    q.push({x,y-1});
                }
                if(x+1 < grid.size() && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    fresh--;
                    q.push({x+1,y});
                }
                if(y+1 < grid[0].size() && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    fresh--;
                    q.push({x,y+1});
                }
            }
            else{
                time++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }
        }

        return fresh==0?time-1 : -1;
    }
};
