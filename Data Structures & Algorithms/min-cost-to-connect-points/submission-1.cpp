class Solution {
public:
    double distance(int x1 , int y1 , int x2 , int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int , double>>> dist(points.size());
        for(int idx1 = 0 ; idx1 < points.size() ; idx1++){
            for(int idx2 = idx1 ; idx2 < points.size() ; idx2++){
                double dista = distance(points[idx1][0] , points[idx1][1] , points[idx2][0] , points[idx2][1]);
                dist[idx1].push_back({idx2 , dista});
                dist[idx2].push_back({idx1 , dista});
            }
        }

        priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > pq;

    vector<bool> visited(points.size(),false);

    int mstWeight = 0;

    pq.push({0,0});

    while(!pq.empty()){

        auto [wt,node] = pq.top();
        pq.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        mstWeight += wt;

        for(auto &[nei,w] : dist[node]){

            if(!visited[nei]){
                pq.push({w,nei});
            }
        }
    }

    return mstWeight;
    }
};
