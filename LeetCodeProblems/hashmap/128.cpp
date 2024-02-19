class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      map<int, int> mappy = {};
      map<int, int> alreadyCovered = {};
      int answer = 0;
      for(int i = 0; i < nums.size(); i++) {
        mappy[nums[i]]++;
      }

      for(int i = 0; i < nums.size(); i++) {
        if (mappy[nums[i]-1] == 0 && alreadyCovered[nums[i]] == 0) {
          alreadyCovered[nums[i]]++;
          int j = nums[i];
          int length = 0;
          while(mappy[j+length] > 0) {
            length++;
            if (length > answer) {
              answer = length;
            }
          }
        }
      }
      return answer; 
    }
};