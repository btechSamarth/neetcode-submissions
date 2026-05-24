class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return false;
        }
        unordered_map<int,int> mp;
        for(auto i : nums){
            if(mp.find(i) != mp.end()){
                return true;
            }
            mp[i]++;
        }
        return false;
    }
};