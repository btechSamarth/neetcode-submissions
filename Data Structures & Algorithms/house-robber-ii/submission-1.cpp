class Solution {
public:
    void solve(vector<int>& nums , int i , int& ans , int temp , vector<vector<int>>& mp , int n){
        if(i >= n){
            ans = max(ans , temp);
            return;
        }

        if(mp[i][temp] != -1){
            return;
        }
        solve(nums , i+2 , ans , temp + nums[i] , mp , n);
        solve(nums , i+1 , ans , temp , mp, n);

        mp[i][temp] = ans;

        return;
    }
    int rob(vector<int>& nums) {
        int ans = 0;
        int s = accumulate(nums.begin() , nums.end() , 0);
        if(s == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        vector<vector<int>> mp(nums.size() , vector<int>(s , -1));
        solve(nums, 0 , ans , 0 , mp , nums.size()-1);
        int ans2 = 0;
        mp.assign(nums.size(), vector<int>(s, -1));
        solve(nums , 1 , ans , 0 , mp , nums.size());
        return ans;
    }
};
