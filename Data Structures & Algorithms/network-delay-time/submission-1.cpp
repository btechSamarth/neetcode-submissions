class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i : times){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1 , INT_MAX);
        vector<int> visited(n+1 , 0);
        dist[k] = 0;
        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int top = q.front();
            q.pop();

            visited[top] = 1;

            for(auto i : adj[top]){
                int v = i.first;
                int w = i.second;
                if(dist[top] + w < dist[v]){
                    dist[v] = dist[top] + w;
                    q.push(v);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1 ; i < n+1 ; i++){
            if(visited[i] == 0) return -1;
            ans = max(ans , dist[i]);
        }
        return ans;
    }
};
