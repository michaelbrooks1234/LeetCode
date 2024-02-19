class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> answer = {};
      map<int, int> covered = {};
      for (int i = 0; i < numbers.size(); i++) {
        if (covered[numbers[i]] > 0) {
          continue;
        }
        covered[numbers[i]]++;
        for (int j = i+1; j < numbers.size(); j++) {
          if (numbers[i] + numbers[j] == target) {
            answer.push_back(i+1);
            answer.push_back(j+1);
          }
        }
      }
      return answer;
    }
};