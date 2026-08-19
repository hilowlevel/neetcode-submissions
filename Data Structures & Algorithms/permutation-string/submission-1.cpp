class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s3(26,0);
        vector<int> s4(26,0);
        int left = 0;
        int right = s1.size() - 1;
        if(s1.size() > s2.size()) return false;
        for(char c : s1) s3[c - 'a']++;
        for(int i = left; i <= right; i++) s4[s2[i] - 'a']++;
        if(s3 == s4) return true;
        while(right < s2.size() - 1){
            s4[s2[left] - 'a']--;
            left++;
            right++;
            s4[s2[right] - 'a']++;
            if(s3 == s4) return true;
            
        }
        return false;
    }
};
