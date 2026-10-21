class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int j = 0;
        int maxcnt = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i<n; i++){
            if (mp.find(s[i]) != mp.end()){
                j = max(j , mp[s[i]] + 1);
            }
            mp[s[i]] = i;
            int cnt = i - j + 1;
            maxcnt = max(maxcnt ,  cnt);
        }
        return maxcnt;
    }
};