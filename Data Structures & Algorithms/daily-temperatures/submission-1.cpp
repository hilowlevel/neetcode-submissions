#include <stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        vector<int> answer(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            if(temp.size() == 0) temp.push(i);
            else{
                while(temp.size() > 0 && temperatures[i] > temperatures[temp.top()]){
                    answer[temp.top()] = i - temp.top();
                    temp.pop();
                }
                temp.push(i);
            }
        }
        return answer;
    }
};
