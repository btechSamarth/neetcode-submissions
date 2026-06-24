class Solution {
public:
    void solve(vector<vector<int>>& dp, string s , int left , int right, string& ans , string temp){
        if(temp.length() > ans.length()){
            ans = temp;
        }
        if(left < 0 || right == s.length()){
            return;
        }
        if(dp[left][right] != -1){
            return ;
        }
        if(s[left] != s[right]){
            return;
        }
        else{
            temp = s.substr(left , right-left+1);
        }
        solve(dp, s , left-1 , right+1 , ans , temp);

        dp[left][right] = ans.length();
        return;
    }
    string longestPalindrome(string s) {
        int len = 0;
        string ans;
        string temp;
        vector<vector<int>> dp(s.length() , vector<int>(s.length() , -1));
        for(int i = 0 ; i < s.length() ; i++){
            solve(dp, s , i , i,  ans , s.substr(i , 1));
            if(i+1 < s.length() && s[i] == s[i+1]){
                solve(dp , s , i , i+1 , ans , s.substr(i , 2));
            }
        }

        return ans;
    }
};
