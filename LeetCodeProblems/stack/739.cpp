#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> answer(temperatures.size());
      stack<pair<int,int>> stacky = {};
      for (int i = 0; i < temperatures.size(); i++) {
        if (stacky.empty()) {
          stacky.push(make_pair(temperatures[i], i));
          continue;
        }
        if (stacky.top().first < temperatures[i]) {
          while(!stacky.empty() && stacky.top().first < temperatures[i]) {
            answer[stacky.top().second] = i - stacky.top().second;
            stacky.pop();
          }
        }
        stacky.push(make_pair(temperatures[i], i));
      }
      return answer;
    }
};