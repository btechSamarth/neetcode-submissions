class Solution {
public:
    void dfs(vector<vector<int>>& heights,
             vector<vector<int>>& vis,
             int i, int j)
    {
        vis[i][j] = 1;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x>=0 && y>=0 &&
               x<heights.size() &&
               y<heights[0].size() &&
               !vis[x][y] &&
               heights[x][y] >= heights[i][j])
            {
                dfs(heights, vis, x, y);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n,0));
        vector<vector<int>> atlantic(m, vector<int>(n,0));

        // Pacific
        for(int i=0;i<m;i++)
            dfs(heights, pacific, i, 0);

        for(int j=0;j<n;j++)
            dfs(heights, pacific, 0, j);

        // Atlantic
        for(int i=0;i<m;i++)
            dfs(heights, atlantic, i, n-1);

        for(int j=0;j<n;j++)
            dfs(heights, atlantic, m-1, j);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};