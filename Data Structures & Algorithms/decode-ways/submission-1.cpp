class Solution {
public:
    void solve(string s , int& count , int i , vector<int>& dp){
        if(i >= s.length()){
            count++;
            return;
        }
        int temp = count;
        if(dp[i] != -1){
            count += dp[i];
            return;
        }
        int num = s[i] - '0';
        if(num){
            solve(s , count , i+1 , dp);
        }
        else{
            return;
        }
        if(i+1 < s.length()){
            int num = ((s[i] - '0') * 10) + ((s[i+1] - '0'));
            if(num<=26){
                solve(s , count , i+2 ,dp);
            }
        }
        dp[i] = count-temp;
        return;
        
    }
    int numDecodings(string s) {
        int count = 0;
        vector<int> dp(s.length() , -1);
        solve(s , count , 0 , dp);
        return count;
    }
};
