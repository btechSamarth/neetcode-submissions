class Solution {
public:
    struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (int x : v)
            h ^= hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        return h;
    }
};
    void solve(vector<vector<int>>& ans , vector<int>& nums , int i , vector<int> temp, unordered_map<vector<int>, int, VectorHash>& mp){
         if(mp.find(temp) != mp.end()){
            return;
        }
        if(i == nums.size()){
            ans.push_back(temp);
            mp[temp]++;
            return;
        }
        temp.push_back(nums[i]);
        solve(ans , nums , i+1 , temp, mp);
        temp.pop_back();

        solve(ans , nums , i+1 , temp, mp);

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        unordered_map<vector<int>, int, VectorHash> mp;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans , nums , 0 , temp , mp);

        return ans;
    }
};
