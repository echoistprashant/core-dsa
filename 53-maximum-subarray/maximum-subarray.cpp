class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currentSum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i<n; i++){
            currentSum = currentSum + nums[i];
            maxSum = max(maxSum,currentSum);
            if(currentSum < 0){
                currentSum = 0;
            }
            
        }
        return maxSum;
    }
};