class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> mp;
        if(s.length() != t.length()){
            return false;
        }
        if(s.length() == 0){
            return true;
        }
        for(auto i : s){
            mp[i]++;
        }
        for(auto i : t){
            if(mp.find(i) != mp.end()){
                if(mp[i] == 0){
                    return false;
                }
                mp[i]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
