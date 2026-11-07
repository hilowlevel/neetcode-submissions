class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int left = grid.size();
        int right = grid[0].size();

        queue<pair<int, int>> q;

        // 모든 보물 상자 탐색
        for(int i = 0; i < left; i++){
            for(int j = 0; j < right; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        // 상하좌우 방향
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int d = 0; d < 4; d++){

                int ni = i + x[d];
                int nj = j + y[d];

                // 배열 범위 검사
                if(ni < 0 || ni >= left ||
                   nj < 0 || nj >= right){
                    continue;
                }

                // 빈 공간이 아닌 경우
                if(grid[ni][nj] != INT_MAX){
                    continue;
                }

                grid[ni][nj] = grid[i][j] + 1;

                q.push({ni, nj});
            }
        }
    }
};