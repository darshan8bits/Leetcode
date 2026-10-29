class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        visited[entrance[0]][entrance[1]] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if(maze[nr][nc] == '+') continue;
                if(visited[nr][nc]) continue;

                if(nr == m - 1 || nc == n - 1 || nr == 0 || nc == 0){
                    return d + 1;
                }

                visited[nr][nc] = true;
                q.push({{nr, nc}, d + 1});
            }

        }

        return -1;
    }
};