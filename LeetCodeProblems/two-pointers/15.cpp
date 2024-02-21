class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer = {};
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (r > l) {
                vector<int> triplet = {};
                if (r < nums.size() - 1 && nums[r] == nums[r+1]) {
                    r--;
                    continue;
                }
                if (l > i + 1 && nums[l] == nums[l-1]) {
                    l++;
                    continue;
                }
                if (nums[j] + nums[k] == target) {
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    answer.push_back(triplet);
                } 
                if (nums[j] + nums[k] > target) {
                    r--;
                    continue;
                }
                l++;
                continue;
            }
        }
        return answer;
    }
};