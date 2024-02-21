class Solution {
public:
    int trap(vector<int>& height) {
      int l = 0;       
      int r = height.size() - 1;
      int answer = 0;
      int maxL = 0;
      int maxR = 0;
      while (l <= r) {
        int minHeight = min(maxL, maxR);
        if (maxL < maxR) {
          answer += max(minHeight - height[l], 0);
          maxL = max(height[l], maxL);
          l++;
          continue;
        }
        answer += max(minHeight - height[r], 0);
        maxR = max(height[r], maxR);
        r--;
        continue;
      }
      return answer;
    }
};