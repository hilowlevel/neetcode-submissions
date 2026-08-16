class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        vector<int> water_left;
        vector<int> water_right;
        int answer = 0;

        int left_max = left;
        int right_max = right;

        for(int i = 0; i < height.size(); i++){
            if(height[i] > height[left_max]) left_max = i;
            water_left.push_back(height[left_max]);
        }
        for(int i = 0; i < height.size(); i++){
            if(height[height.size() - i - 1] > height[right_max]) right_max = height.size() - i - 1;
            water_right.insert(water_right.begin(), height[right_max]);
        }
        for(int i = 0; i < height.size(); i++){
            answer += (min(water_left[i], water_right[i]) - height[i]);
        }
            
        return answer;
    }
};
