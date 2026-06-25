class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> indegree(num);
        for(auto i : pre){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            count++;
            for(auto i : adj[a]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        return count == num ? true : false;
    }
};
