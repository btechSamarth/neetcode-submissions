class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int steps = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : flights){
            int u = i[0]; int v = i[1]; int w = i[2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>> q;
        q.push({src , 0});
        q.push({-1,-1});

        while(!q.empty()){
            pair<int,int> top = q.front();
            q.pop();

            if(top.first != -1){
                dist[top.first] = min(top.second , dist[top.first]);
                if(steps > k){
                    continue;
                } 
                for(auto i : adj[top.first]){
                    int v = i.first;
                    int w = i.second;
                    if(dist[top.first] + w  < dist[v]){
                        q.push({v , dist[top.first] + w});
                    }
                }
            }
            else{
                steps++;
                if(!q.empty()) q.push({-1,-1});
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
