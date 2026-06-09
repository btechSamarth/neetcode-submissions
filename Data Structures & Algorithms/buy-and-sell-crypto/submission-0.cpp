class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxy = prices[0];
        int ans = maxy - mini;

        for(int i = 1 ; i < prices.size() ; i++){
            int temp;
            if(prices[i] < mini){
                mini = prices[i];
                maxy = prices[i];
            }
            else{
                if(maxy <= prices[i]){
                    maxy = prices[i];
                }
            }

            temp = maxy - mini;
            ans = max(ans , temp);
        }

        return ans;
    }
};
