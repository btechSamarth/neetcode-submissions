class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            int correct = nums[i]-1;

            if(nums[i] != nums[correct]){
                swap(nums[correct] , nums[i]);
            }
            else{
                i++;
            }
        }

        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j] != j+1){
                return nums[j];
            }
        }

        return -1;
    }
};
