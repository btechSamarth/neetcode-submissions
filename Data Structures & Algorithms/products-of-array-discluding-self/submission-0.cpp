class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0;
        int product = 1;
        int idx = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                count++;
                idx = i;
            }
            else{
                product *= nums[i];
            }
        }
       
        if(count > 1){
            vector<int> ans(nums.size() , 0);
            return ans;
        }
        else if(count == 1){
            vector<int> ans(nums.size() , 0);
            ans[idx] = product;
            return ans;
        }
        else{
            vector<int> ans;
            for(int i = 0 ; i < nums.size() ; i++){
                int num = product/nums[i];
                ans.push_back(num);
            }
            return ans;
        }
        return {};
    }
};
