#include <unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> temp;
        int left = 0;
        int right = 0;
        int maxint = 0;
        int ans = 0;
        

        while(right < s.size()){
            temp[s[right]]++;
            maxint = max(temp[s[right]], maxint);
            while((right - left + 1) - maxint > k){
                temp[s[left]]--;
                left++;
            }
            ans = max(right - left + 1, ans);
            right++;
        }
        return ans;
    }
};
