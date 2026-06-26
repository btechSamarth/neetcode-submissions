class Solution {
public:
    bool solve(string& s , unordered_set<string>& st , int si , vector<int>& dp){
        if(si >= s.length()){
            return true;
        }

        if(dp[si] != -1){
            return dp[si];
        }
        int left = si;
        int right = si;
        while(right < s.length()){
            string temp = s.substr(left , right-left+1);
            //cout << temp << endl;
            if(st.find(temp) != st.end()){
                if(solve(s , st , right+1 , dp)){
                    return dp[si] = true;
                }
            }
            right++;
        } 
        return dp[si] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0){
            return true;
        }
        unordered_set<string> st;
        vector<int> dp(s.length() , -1);
        for(auto i: wordDict){
            st.insert(i);
        }
        for(auto i : wordDict){
            int a = i.length();
            if(i == s.substr(0 , a)){
                if(solve(s , st , a , dp)) return true;
            }
        }

        return false;
    }
};
