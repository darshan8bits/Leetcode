class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }  
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }    
    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            swap(pu, pv);
        }

        size[pu] += size[pv];
        parent[pv] = pu;
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
    int getsize(int v){
        return size[find(v)];
    }
}; 
    
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int maxm = 0;
        for(auto &v : edges){
            maxm = max(maxm, max(v[0], v[1]));
        }
        vector<int> ans;
        DSU dsu(maxm);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            if(dsu.find(u) == dsu.find(v)){
                ans = {u, v};
            }
            dsu.unite(u, v);
        }
        return ans;
    }
};
