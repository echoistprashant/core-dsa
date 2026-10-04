class Solution {
    vector<vector<int>> threeSum(vector<int>& nums, int start, long long target) {
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = start; i < n - 2; i++) {
            if(i > start && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];

                if(sum < target) {
                    left++;
                }
                else if(sum > target) {
                    right--;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left + 1])
                        left++;

                    while(left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
            }
        }

        return ans;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            long long newTarget = (long long)target - nums[i];

            vector<vector<int>> triplets = threeSum(nums, i + 1, newTarget);

            for(auto triplet : triplets) {
                ans.push_back({nums[i], triplet[0], triplet[1], triplet[2]});
            }
        }

        return ans;
    }
};