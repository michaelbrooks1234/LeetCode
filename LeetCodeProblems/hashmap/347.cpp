class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int size = nums.size();
      vector<vector<int>> bucket(size); 
      map<int, int> mappy = {};
      vector<int> answer = {};
      for (int i = 0; i < size; i++) {
          mappy[nums[i]]++;
      }
      for(auto const& x : mappy) {
        bucket[x.second].push_back(x.first);
      }
      for(int i = size-1; i >= 0; i--) {
        for (int y = 0; y < bucket[i].size(); y++) {
          answer.push_back(bucket[i][y]);
          if (answer.size() == k) {
            return answer;
          }
        }
      }
      return answer;
    }
};