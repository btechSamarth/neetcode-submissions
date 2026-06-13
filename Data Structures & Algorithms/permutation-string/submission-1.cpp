class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> temp1(26 , 0);
       for(auto i : s1){
            temp1[i-'a']++;
       }
       vector<int> temp2(26 , 0);
       int left = 0;
       for(int right = 0 ; right < s2.length() ; right++){
            temp2[s2[right]-'a']++;

            while(temp2[s2[right]-'a'] > temp1[s2[right]-'a']){
                temp2[s2[left]-'a']--;
                left++;
            }

            if(temp1 == temp2){
                return true;
            }
       }
       return false;
    }
};
