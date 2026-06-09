class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> temp;
        for(auto i : stones){
            temp.push(i);
        }
        if(temp.size() == 0){
            return 0;
        }
        while(temp.size() > 1){
            int a = temp.top();
            temp.pop();
            int b = temp.top();
            temp.pop();
            if(a < b){
                temp.push(b-a);
            }
            else if(a > b){
                temp.push(a-b);
            }
        }
        return temp.size() == 1 ? temp.top() : 0;
    }
};
