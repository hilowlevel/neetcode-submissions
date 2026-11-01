class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int a = 0b0;
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i = 0; i < pow(2, nums.size()); i++){
            temp = {};
            int count = 0;
            while(a>>count != 0){
                if((a>>count)%2 == 1){
                    temp.push_back(nums[count]);
                }
                count++;
            }
            ans.push_back(temp);
            a++;
        }
        return ans;
    }
};
