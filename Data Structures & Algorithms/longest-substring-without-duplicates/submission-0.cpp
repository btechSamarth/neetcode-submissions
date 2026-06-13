class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int ans = INT_MIN;
        unordered_map<char , int> mp;
        int left = 0;
        for(int right = 0 ; right < s.length() ; right++){
            mp[s[right]]++;
            
            while(mp[s[right]] != 1){
                mp[s[left]]--;
                left++;
            }

            ans = max(ans , right-left+1);
        }
        return ans;
    }
};
