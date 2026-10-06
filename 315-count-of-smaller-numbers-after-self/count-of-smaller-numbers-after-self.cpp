class Solution {
    vector<int> ans;
    
    void merge(vector<pair<int,int>>& arr, int low, int mid, int high) {
        vector<pair<int,int>> temp;
        int i = low;
        int j = mid + 1;
        int rightCount = 0;

        while(i <= mid && j <= high) {
            if(arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                rightCount++;
                j++;
            }
            else {
                ans[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while(i <= mid) {
            ans[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }

        while(j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        for(int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    void mergeSort(vector<pair<int,int>>& arr, int low, int high) {
        if(low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n, 0);

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1);

        return ans;
    }
};