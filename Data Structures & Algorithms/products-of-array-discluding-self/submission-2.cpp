class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int total = 1;
        int exp = 1;
        
        for(int i = 0; i < nums.size(); i++){
            total *= nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                exp = 1;
                for(int j = 0; j < nums.size(); j++){
                    if(j != i){
                        exp *= nums[j];
                    }
                    
                }
                ans.push_back(exp);
            }
            else{
                ans.push_back(total/nums[i]);
            }
            
        }
        return ans;
    }
};
