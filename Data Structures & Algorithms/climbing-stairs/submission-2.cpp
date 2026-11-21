class Solution {
public:
    int climbStairs(int n) {
        int stair1 = 1;
        int stair2 = 1;
        int cur;
        if(n == 1) return 1;
        for(int i = 2; i <= n; i++){
            cur = stair1 + stair2;
            stair2 = stair1;
            stair1 = cur;
        }
        return cur;
    }
};
