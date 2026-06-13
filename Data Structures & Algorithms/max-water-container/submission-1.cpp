class Solution {
public:
    int maxArea(vector<int>& heights) {
       int left = 0;
       int right = heights.size()-1;
        int ans = INT_MIN;
        while(left <= right){
            int num = min(heights[left] , heights[right]);
            ans = max(ans , num*(right-left));
            //cout << heights[left] << " " << heights[right] << endl;
            if(heights[left] <= heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};
