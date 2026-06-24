class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto i : hand){
            mp[i]++;
        }

        for(auto [card , freq] : mp){
            while(mp[card] > 0){
                for(int j = card ; j < card + groupSize ; j++){
                    if(mp[j] == 0){
                        return false;
                    }
                    mp[j]--;
                }
            }
        }
        return true;
    }
};
