class Solution {
public:

    bool issafe(vector<string> temp , string s){
        if(temp.size() == 0){
            return true;
        }
        else{
            string s1 = temp[0];
            if(s1.length() != s.length()){
                return false;
            }
            vector<int> v(26 , 0);

            for(auto i : s1){
                v[i-'a']++;
            }

            for(auto i : s){
                if(v[i-'a'] == 0){
                    return false;
                }
                else{
                    v[i-'a']--;
                }
            }

            return true;
        }
    }

    void solve(vector<string>& s, vector<vector<string>>& ans , vector<string>& temp , int i , unordered_map<string , int>& mp){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }
        bool flag = false;
        if(mp.find(s[i]) == mp.end()){
            flag = issafe(temp , s[i]);
        }
        if(flag){
            mp[s[i]] = 1;
            temp.push_back(s[i]);
            mp.erase(s[i]);
            solve(s , ans , temp , i+1 , mp);
            temp.pop_back();
            mp[s[i]] = 1;
        }
        if(temp.size() == 0 || flag == false) solve(s , ans , temp , i+1 , mp);
        

        return;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> temp;
        unordered_map<string , int> visited;
        solve(strs , ans , temp , 0 , visited);

        if(ans.size() != 0){
            ans.pop_back();
        }

        return ans;
    }
};
