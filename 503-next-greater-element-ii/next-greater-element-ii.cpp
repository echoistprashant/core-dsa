
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int nge = -1;

            for (int j = i + 1; j <= i + n - 1; j++) {
                int index = j % n;

                if (nums[index] > nums[i]) {
                    nge = nums[index];
                    break;
                }
            }

            ans.push_back(nge);
        }

        return ans;
    }
};
