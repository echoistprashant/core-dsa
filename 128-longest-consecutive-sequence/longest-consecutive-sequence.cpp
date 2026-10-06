class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        for(int num:st){
           if(st.find(num-1)==st.end()){
            int current = num;
            int cnt = 1;
            while(st.find(current+1)!=st.end()){
                current++;
                cnt++;
            }
            ans = max(cnt,ans);
           }
        }
        return ans;
    }
};