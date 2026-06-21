class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(speed.size() == 1){
            return 1;
        }
        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end() , greater<>());   // sorts by position
        
        stack<double> st;
        int count = 0;
        for(auto i : cars){
            pair<int,int> temp = i;
            double pos = temp.first;
            double s = temp.second;
            double time = (target - pos)/s;
            cout << time << endl;
            if(st.empty()){
                st.push(time);
                cout << st.top() << endl;
                count++;
            }
            else{
                if(time > st.top()){
                    st.push(time);
                    cout << st.top() << endl;
                    count++;
                }
            }
        }
        return count;
    }
};
