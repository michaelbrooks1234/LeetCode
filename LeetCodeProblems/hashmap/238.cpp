class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int size = nums.size();
      map<int, int> mapLeft, mapRight = {};
      vector<int> answer = {};
      for (int i = 0; i < size; i++) {
        if (i == 0) {
          mapLeft[i] = nums[i];
          mapRight[size-i-1] = nums[size - i - 1];
          continue;
        }
        mapLeft[i] = nums[i] * mapLeft[i-1];
        mapRight[size-i-1] = nums[size - i - 1] * mapRight[size - i];
      }
      for (int i = 0; i < size; i++) {
        if (i == 0) {
          answer.push_back(mapRight[i+1]);
          continue;
        }
        if (i == size-1) {
          answer.push_back(mapLeft[i-1]);
          continue;
        }
        answer.push_back(mapLeft[i-1] * mapRight[i+1]);
      }
      return answer;
    }
};