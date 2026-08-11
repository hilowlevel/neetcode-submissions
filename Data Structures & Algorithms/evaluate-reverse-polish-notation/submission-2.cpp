#include <stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int a;
        int b;
        int temp;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a + b);
            }
            else if(tokens[i] == "-"){
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a - b);
            }
            else if(tokens[i] == "*"){
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a * b);
            }
            else if(tokens[i] == "/"){
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a / b);
            }
            else{
                temp = stoi(tokens[i]);
                nums.push(temp);
            }
        }
        return nums.top();
    }
};
