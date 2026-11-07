class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i<nums1.size(); i++){
            int nge = -1;
            int index = 1;

            for(int j = 0; j < nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                    index = j;
                    break;
                }
            }

            for(int j = index+1; j < nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    nge = nums2[j];
                    break;
                }
            }
            ans.push_back(nge);
        }
        return ans;
    }
};