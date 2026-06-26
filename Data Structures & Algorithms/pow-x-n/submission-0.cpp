class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n < 0){
            x = 1/x;
        }
        n = abs(n);
        double sq = x*x;
        double prod = 1;
        for(int i = 0 ; i < n ; i+=2){
            cout << prod << endl;
            if(n-1 == i){
                prod *= x;
            }
            else{
                prod *= sq;
            }
        }
        return prod;
    }
};
