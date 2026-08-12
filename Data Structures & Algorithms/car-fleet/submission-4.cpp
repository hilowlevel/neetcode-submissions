#include <stack>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> car;
        stack<int> num;
        int max = 0;
        int ans = 0;
        
        for(int i = 0; i < speed.size(); i++) car.push_back({position[i], speed[i]});
        sort(car.begin(), car.end());

        for(int i = 0; i < speed.size(); i++){
            if(num.size() == 0) num.push(10*(target - car[i][0])/car[i][1]);
            else{
                if(num.top() <= 10*(target - car[i][0])/car[i][1]){
                    num.pop();
                    num.push(10*(target - car[i][0])/car[i][1]);
                }
                else num.push(10*(target - car[i][0])/car[i][1]);
            }
        }
        int size = num.size();
        for(int i = 0; i < size; i++){
            if(num.top() > max) max = num.top();
            num.pop();
            if(num.size() == 0){
                ans++;
                break;
            }
            if(max < num.top()){
                ans++;
                max = num.top();
            }
        }
        return ans;
    }
};
