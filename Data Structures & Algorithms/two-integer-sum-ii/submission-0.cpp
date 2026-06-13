class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int right = num.size()-1;
        int left = 0;
        while(left < right){
            int sum = num[right] + num[left];
            if(sum == target){
                return {left+1 , right+1};
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1,-1};
    }
};
