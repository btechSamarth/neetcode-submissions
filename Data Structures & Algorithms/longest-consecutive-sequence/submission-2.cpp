class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        int ans = 1;
        for(auto i : nums){
            if(s.find(i-1) != s.end()){
                continue;
            }
            else{
                int count = 1;
                int j = i;
                while(s.find(j+1) != s.end()){
                    count++;
                    j++;
                }
                ans = max(ans , count);
            }
        }
        return ans;
    }
};
