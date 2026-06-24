class Solution {
public:
    void solve(string& s , int left , int right, int& count){
        if(left < 0 || right == s.length()){
            return;
        }
        if(s[left] != s[right]){
            return;
        }
        count++;
        solve(s , left-1 , right+1 , count);

        return;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0 ; i < s.length() ; i++){
            solve(s , i , i,  count);
            if(i+1 < s.length() && s[i] == s[i+1]){
                solve(s , i , i+1 , count);
            }
        }

        return count;
    }
};