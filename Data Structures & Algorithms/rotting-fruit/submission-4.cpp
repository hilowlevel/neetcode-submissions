class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int x = grid.size();
        int y = grid[0].size();
        int ans = -1;
        int check = 0;

        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = 100;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            vector<int> k = {-1, 1, 0, 0};
            vector<int> l = {0, 0, -1, 1};

            for(int d = 0; d < 4; d++){
                int ni = i + k[d];
                int nj = j + l[d];

                if(ni < 0 || ni >= x || nj < 0 || nj >= y) continue;

                if(grid[ni][nj] != 1) continue;

                grid[ni][nj] = grid[i][j] + 1;
                q.push({ni, nj});
                ans = max(grid[i][j] + 1, ans);
                check = 1;
            }

        }

        if(check == 0){
            for(int i = 0; i < x; i++){
                for(int j = 0; j < y; j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }
            return 0;
        }
        
        for(int i = 0; i < x; i++){
                for(int j = 0; j < y; j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }
        return ans - 100;
        
    }
};
