class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        vector<bool> visited(numCourses, false);
        vector<vector<int>> adj(numCourses);
        
        for(auto &v : prerequisites){
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
                visited[i] = true;
            }
        }

        vector<int> ordering;

        while(!q.empty()){
            int node = q.front();
            ordering.push_back(node);
            q.pop();

            for(auto &n : adj[node]){
                if(visited[n]) continue;
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                    visited[n] = true;
                }
            }
        }

        return ordering.size() == numCourses;
    }
};