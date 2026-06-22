class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = 0;
        int b = 0;
        int c = 0;

        for(auto i : triplets){
            bool flag = false;
            for(int j = 0 ; j < 3 ; j++){
                if(i[j] > target[j]){ flag = true; break;}
            }
            if(flag) continue;
            a = max(i[0] , a);
            b = max(i[1] , b);
            c = max(i[2] , c);
        }

        if(a == target[0] && b== target[1] && c == target[2]){
            return true;
        }

        return false;
    }
};
