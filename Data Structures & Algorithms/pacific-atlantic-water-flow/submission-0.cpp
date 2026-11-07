class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> q;
        vector<vector<int>> ans;
        int x = heights.size();
        int y = heights[0].size();
        
        
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                vector<vector<int>> check(x, vector<int>(y, 0));
                q.push({i, j});
                int chk1 = 0;
                int chk2 = 0;

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    if(r == 0 || c == 0) chk1 = 1;
                    if(r == x - 1 || c == y - 1) chk2 = 1;
                    q.pop();

                    vector<int> a = {-1, 1, 0, 0};
                    vector<int> b = {0, 0, -1, 1};

                    for(int k = 0; k < 4; k++){
                        int nr = r + a[k];
                        int nc = c + b[k];

                        if(nr < 0 || nr >= x || nc < 0 || nc >= y) continue;
                        if(check[nr][nc] == 1) continue;

                        if(heights[nr][nc] <= heights[r][c]){
                            q.push({nr, nc});
                            check[nr][nc] = 1;
                            if(nr == 0 || nc == 0) chk1 = 1;
                            if(nr == x - 1 || nc == y - 1) chk2 = 1;
                        }
                    }
                }
                if(chk1 == 1 && chk2 == 1) ans.push_back({i, j});

            }
        }
        //if(y != 1) ans.push_back({0, y - 1});
        //if(x != 1) ans.push_back({x - 1, 0});
        return ans;

    }
};
