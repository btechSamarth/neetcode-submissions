class Solution {
public:
    double solve(int x1 , int y1){
        return sqrt(pow((x1 - 0) , 2) + pow((y1 - 0),2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int> , vector<pair<double,int>> , greater<pair<double,int>>> pq;
        for(int i = 0 ; i < points.size() ; i++){
                int x = points[i][0];
                int y = points[i][1];
                double dist = solve(x , y);
                cout << dist << endl;
                pq.push({dist , i});
        }
        vector<vector<int>> ans;
        for(int i = 0 ; i < k ; i++){
            pair<int,int> temp = pq.top();
            int j = temp.second;
            pq.pop();
            ans.push_back({points[j][0] , points[j][1]});
        }

        return ans;
    }
};
