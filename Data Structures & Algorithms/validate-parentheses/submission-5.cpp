#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<int> sta;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                sta.push(1);
            }
            else if(s[i] == '{'){
                sta.push(2);
            }
            else if(s[i] == '['){
                sta.push(3);
            }
            else if(s[i] == ')'){
                if(sta.size() == 0) return false;
                if(sta.top() != 1) return false;
                else sta.pop();
            }
            else if(s[i] == '}'){
                if(sta.size() == 0) return false;
                if(sta.top() != 2) return false;
                else sta.pop();
            }
            else if(s[i] == ']'){
                if(sta.size() == 0) return false;
                if(sta.top() != 3) return false;
                else sta.pop();
            }
            
            
        }
        if(sta.size() == 0) return true;    
        else return false;
    }
};
