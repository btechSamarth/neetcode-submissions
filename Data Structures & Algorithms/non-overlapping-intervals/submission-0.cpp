class Solution {
public:
    bool static cmp(vector<int> &a , vector<int> &b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , cmp);
        int count = 0;
        vector<int> top = intervals[0];
        int idx = 1;

        while(idx < intervals.size()){
            int first = top[0];
            int second = top[1];
            int third = intervals[idx][0];
            int fourth = intervals[idx][1];

            if(third < second){
                top[1] = min(second , fourth);
                count++;
            }
            else{
                top[1] = fourth;
            }

            idx++;
        }
        return count;
    }
};
