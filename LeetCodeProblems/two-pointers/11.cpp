class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int i = 0;
        int j = height.size()-1;
        while (i < j) {
            int width = j - i;
            int heighty = min(height[i], height[j]);
            answer = max((heighty * width), answer);   
            if (height[i] > height[j]) {
              j--;
              continue;
            }
            i++;
            continue;
        }
        return answer;
};