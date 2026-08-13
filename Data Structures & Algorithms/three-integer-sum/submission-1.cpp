class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
;
        for(int middle = 1; middle < nums.size() - 1; middle++){
            left = 0;
            right = nums.size() - 1;
            while(left < middle && right > middle){
                if(nums[left] + nums[middle] + nums[right] > 0) right--;
                else if(nums[left] + nums[middle] + nums[right] < 0) left++;
                else {
                    answer.push_back({nums[left], nums[middle], nums[right]});
                    left++;
                }
            }
        }
        std::sort(answer.begin(), answer.end());
        auto last = std::unique(answer.begin(), answer.end());
        answer.erase(last, answer.end());


        return answer;
    }
};
