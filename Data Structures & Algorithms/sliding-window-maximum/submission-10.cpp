#include <queue>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 1;
        int right = k;
        vector<int> ans;
        std::priority_queue<std::pair<int, int>> heap;
        
        for(int i = 0; i < k; i++){
            heap.push({nums[i], i});
        }

        ans.push_back(heap.top().first);

        while(right < nums.size()){
            while(heap.size() != 0 && left - 1 >= heap.top().second) heap.pop();
            heap.push({nums[right], right});
            ans.push_back(heap.top().first);
            left++;
            right++;
        }

        return ans;
    }
};
