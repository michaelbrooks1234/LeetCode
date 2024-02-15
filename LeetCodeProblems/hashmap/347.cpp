// solution utilizes bucket sort.


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int size = nums.size();
      // initilize empty 2d array with the size of nums + 1 to use for bucket sort
      vector<vector<int>> bucket(size+1); 
      map<int, int> mappy = {};
      vector<int> answer = {};

      // get counts of each number in original array
      for (int i = 0; i < size; i++) {
          mappy[nums[i]]++;
      }

      // for the nums in array, add them to the bucket indexed by their occurances in the original array
      for(auto const& x : mappy) {
        bucket[x.second].push_back(x.first);
      }
      // loop through the buckets and add the numbers to the final answer array until the array size == k
      for(int i = size; i >= 0; i--) {
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