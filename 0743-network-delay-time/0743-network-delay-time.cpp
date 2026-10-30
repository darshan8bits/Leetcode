class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &vec : times){
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];
            adj[u].push_back({v, t});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v, w] : adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxm = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            maxm = max(maxm, dist[i]);
        } 

        return maxm;
    }
};
