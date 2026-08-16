class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int answer = min(heights[left], heights[right]) * (right - left);
        int new_ans;
        while(left < right){
            if(heights[left] < heights[right]) left++;
            else right--;
            new_ans = min(heights[left], heights[right]) * (right - left);
            if(new_ans > answer) answer = new_ans;
        }
        return answer;
    }
};
