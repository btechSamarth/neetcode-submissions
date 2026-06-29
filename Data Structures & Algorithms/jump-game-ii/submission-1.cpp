class Solution {
public:

    int solve(int i , vector<int>& nums , vector<int>& mp , int cost , int& ans){
        if(i >= nums.size()-1){
            ans = min(ans , cost);
            return cost;
        }
        int num = nums[i];  
        if(mp[i] != -1){
            if(mp[i] == INT_MAX) return INT_MAX;
            ans = min(ans , cost + mp[i]);
            return cost + mp[i];
        }
        int temp2 = INT_MAX;
        for(int j = num ; j > 0 ; j--){
            temp2 = min(temp2 , solve(i+j , nums , mp , cost+1 , ans));
        }

        return mp[i] = temp2;
    }

    int jump(vector<int>& nums) {
        int ans = INT_MAX;
        vector<int> mp(nums.size() , -1);
        solve(0 , nums , mp , 0 , ans);
        return ans;
    }
};


