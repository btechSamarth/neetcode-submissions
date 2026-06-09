class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xory = 0;
        for(auto i : nums){
            xory = xory xor i;
        }
        return xory;
    }
};
