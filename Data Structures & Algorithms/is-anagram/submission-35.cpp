#include <list>
#include <algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        list<char> lst1;
        list<char> lst2;
        for(int i = 0; i < s.length(); i++){
            lst1.push_back(s[i]);
        }

        for(int i = 0; i < t.length(); i++){
            lst2.push_back(t[i]);
        }
        lst1.sort();
        lst2.sort();

        if (lst1 == lst2){
            return true;
        }
        
        return false;

    }
};
