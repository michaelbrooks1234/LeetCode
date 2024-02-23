#include <vector>

class Solution {
public:
    static bool sortFn(pair<int, int> a, pair<int, int> b) {
      return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      vector<pair<int,int>> cars = {};
      int answer = 0;
      for(int i = 0; i < position.size(); i++) {
        cars.push_back(make_pair(speed[i], position[i]));
      }
      sort(cars.begin(), cars.end(), sortFn);
      for(int i = 0; i < cars.size(); i++) {
        cout << cars[i].first << ' ' << cars[i].second << endl;
      }
      return answer;
    }
};