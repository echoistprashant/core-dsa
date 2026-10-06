class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currentMax = nums[0];
        int currentMin = nums[0];
        int ans = nums[0];
        
        for(int i =1; i < n; i++){
            int x = nums[i];
            int tempMax = max({x, x * currentMax, x * currentMin});
            int tempMin = min({x, x * currentMax, x * currentMin});
            currentMax = tempMax;
            currentMin = tempMin;
            ans = max(currentMax,ans);
        }
        return ans;
    }
};