#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_set<char> temp;
        for(int i = 0; i < s.size(); i++){
            if(temp.find(s[i]) == temp.end()) temp.insert(s[i]);
            else{
                while(temp.find(s[i]) != temp.end()){
                    left++;
                    temp.erase(s[left - 1]);
                }
                temp.insert(s[i]);
            }
            right++;
            if(ans < right - left) ans = right - left;
            
        }
        return ans;
    }
};
