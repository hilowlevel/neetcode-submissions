class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> temp;
        vector<int> ans;
        int cnt = 1;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            cnt++;
            if(i == nums.size() - 1){
                temp.push_back({cnt, nums[i]});
            }
            else if(nums[i] != nums[i+1]){
                temp.push_back({cnt, nums[i]});
                cnt = 1;
            }
        }

        std::sort(temp.begin(), temp.end());
        for(int i = 0; i < k; i++){
            ans.push_back(temp[temp.size() - 1 - i][1]);
        }
        return ans;
    }
};
