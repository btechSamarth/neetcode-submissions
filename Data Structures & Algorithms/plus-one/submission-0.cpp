class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin() , digits.end());
        int carry = 0;
        int i = 0;
        int flag = true;
        do{
            if(flag){
                int num = digits[i] + 1 + carry;
                int a = num%10;
                carry = num/10;
                digits[i] = a;
                flag = false;
                i++;    
            }
            else{
                int num = digits[i] + carry;
                int a = num%10;
                carry = num/10;
                digits[i] = a;
                i++; 
            }
            
        }
        while(carry != 0 && i < digits.size());

        if(carry != 0){
            digits.push_back(1);
        }
      reverse(digits.begin() , digits.end());
      return digits;
        
    }
};
