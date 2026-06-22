class Solution {
public:
    
bool static cmp(vector<int> &a , vector<int> &b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , cmp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int idx = 1;
        while(idx < intervals.size()){

            int second = ans.back()[1];
            int third = intervals[idx][0];
            int fourth = intervals[idx][1];

            if(third < second){
                ans.back()[1] = max(fourth , second);
            }
            else if(third == second){
                ans.back()[1] = fourth;
            }
            else{
                ans.push_back(intervals[idx]);
            }
            idx++;
        }
        return ans;
    }
};


    
