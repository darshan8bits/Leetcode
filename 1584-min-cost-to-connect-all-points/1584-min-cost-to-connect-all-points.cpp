class Solution {
public:
    int prims(vector<vector<pair<int, int>>> &adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int cost = 0;

    vector<bool> visited(adj.size() + 1, false);

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;

        cost += w;

        for(auto &v : adj[u]){
            if(!visited[v.first]){
                pq.push({v.second, v.first});
            }
        }

    }
    return cost;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2 - x1) + abs(y2 - y1);
                adj[i + 1].push_back({j + 1, dist});
                adj[j + 1].push_back({i + 1, dist});
            }
        }

        int ans = prims(adj);

        return ans;
    }
};
