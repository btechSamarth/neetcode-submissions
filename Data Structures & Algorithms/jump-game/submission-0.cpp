class Solution {
public:
    bool solve(int i , vector<int>& nums , vector<int>& mp){
        if(i >= nums.size()-1){
            return true;
        }
        int num = nums[i];
        if(mp[i] != -1){
            return mp[i];
        }
        bool res = false;
        for(int j = num ; j > 0 ; j--){
            res = res | solve(i+j , nums , mp);
            if(res){
                return mp[i] = res;
            }
        }

        return mp[i] = res;
    }
    bool canJump(vector<int>& nums) {
        vector<int> mp(nums.size() , -1);
        return solve(0 , nums , mp);
    }
};
