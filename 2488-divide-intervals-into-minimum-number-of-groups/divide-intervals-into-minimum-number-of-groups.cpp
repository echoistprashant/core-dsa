class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
       vector<int> start;
       vector<int> end;
       for(int i = 0; i < n; i++){
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
       }
       sort(start.begin(),start.end());
       sort(end.begin(),end.end());

       int group = 0;
       int active = 0;
       int i = 0;
       int j = 0;

       while(i<n){
        if(start[i] <= end[j]){
            active = active + 1;
            group = max(group,active);
            i = i+1;
        }
        else{
            active = active - 1;
            j = j+1;
        }
       }
    return group;

    }
};