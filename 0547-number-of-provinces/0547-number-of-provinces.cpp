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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    dsu.unite(i + 1, j + 1);
                }
            }
        }

        int c = 0;

        for(int i = 1; i <= n; i++){
            if(dsu.parent[i] == i) c++;
        }

        return c;
    }
};