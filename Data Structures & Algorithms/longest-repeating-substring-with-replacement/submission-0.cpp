class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int major = 0;
        int ans = INT_MIN;
        unordered_map<char , int> mp;
        for(int right = 0 ; right < s.length() ; right++){
            mp[s[right]]++;
            major = max(major , mp[s[right]]);
            int len = right-left+1;
            while(len - major > k){
                mp[s[left]]--;
                left++;
                major = max(major , mp[s[left]]);
                len = right - left +1;
            }

            ans = max(ans , len);
        }
        return ans;
    }
};
