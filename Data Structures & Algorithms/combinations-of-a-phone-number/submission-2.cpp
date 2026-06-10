class Solution {
public:
    void solve(vector<string> &ans , vector<vector<char>> &choice, string temp , int j){
        
        if(temp.length() == choice.size()){
            ans.push_back(temp);
            return;
        }

        if(j >= choice.size()){
            return;
        }
        for(int i = 0 ; i < choice[j].size() ; i++){
            solve(ans , choice , temp+choice[j][i], j+1);
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> mp = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8',{'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        if(digits.length() == 0){
            return {};
        }
        vector<string> ans;
        vector<vector<char>> choice;

        for(auto i : digits){
            choice.push_back(mp[i]);
        }
        string temp = "";
        solve(ans , choice , temp , 0);
        return ans;
    }
};
