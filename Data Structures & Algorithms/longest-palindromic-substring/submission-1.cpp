class Solution {
public:
    void solve(string& s , int left , int right, string& ans){
        if(left < 0 || right == s.length()){
            return;
        }
        if(s[left] != s[right]){
            return;
        }
        if(right-left+1 > ans.length()){
            ans = s.substr(left , right-left+1);
        }
        solve(s , left-1 , right+1 , ans);

        return;
    }
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0 ; i < s.length() ; i++){
            solve(s , i , i,  ans);
            if(i+1 < s.length() && s[i] == s[i+1]){
                solve(s , i , i+1 , ans);
            }
        }

        return ans;
    }
};
