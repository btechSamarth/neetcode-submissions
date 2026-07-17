class Solution {
public:
    vector<int> countBits(int n) {  
        vector<int> ans;
        ans.push_back(0);
        if(n== 0){
            return ans;
        }      
        for(int i = 1; i <= n ; i++){
            int num1 = i & 1;
            int num2 = i >> 1;
            ans.push_back(num1 + ans[num2]);
        }
        return ans;
    }
};
