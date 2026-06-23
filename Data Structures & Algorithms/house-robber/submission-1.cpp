class Solution {
public:
    void solve(vector<int>& nums , int i , int& ans , int temp , vector<vector<int>>& mp){
        if(i >= nums.size()){
            ans = max(ans , temp);
            return;
        }

        if(mp[i][temp] != -1){
            return;
        }
        solve(nums , i+2 , ans , temp + nums[i] , mp);
        solve(nums , i+1 , ans , temp , mp);

        mp[i][temp] = ans;

        return;
    }
    int rob(vector<int>& nums) {
        int ans = 0;
        int s = accumulate(nums.begin() , nums.end() , 0);
        if(s == 0){
            return 0;
        }
        vector<vector<int>> mp(nums.size() , vector<int>(s , -1));
        solve(nums, 0 , ans , 0 , mp);
        return ans;
    }
};
