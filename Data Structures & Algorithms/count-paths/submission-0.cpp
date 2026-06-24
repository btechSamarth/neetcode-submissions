class Solution {
public:
    void solve(int i , int j, int m , int n , vector<vector<int>>& dp , int& ans){
        if(i == m || j == n){
            return;
        }
        if(i == m-1 && j == n-1){
            ans++;
            return;
        }
        int temp = ans;
        if(dp[i][j] != -1){
            ans += dp[i][j];
            return;
        }
        solve(i+1 , j , m , n , dp , ans);
        solve(i , j+1 , m , n , dp , ans);

        dp[i][j] = ans-temp;

        return;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));
        int ans = 0;
        solve(0 , 0, m , n , dp , ans);

        return ans;
    }
};
