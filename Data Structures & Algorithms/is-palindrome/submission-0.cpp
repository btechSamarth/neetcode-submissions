#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto i : s){
            i = tolower(i);
            if(isalnum(i)){
                temp+=i;
            }
        }
        string s2 = temp;
        reverse(temp.begin() , temp.end());
        if(temp == s2){
            return true;
        }
        else{
            return false;
        }
    }
};
