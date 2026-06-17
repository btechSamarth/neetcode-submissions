class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t a = 1;
        for(int i = 0 ; i < 32 ; i++){
            uint32_t b = a & n;
            cout << b << endl;
            if(b) count++;
            n = n>>1;
        }
        return count;
    }
};
