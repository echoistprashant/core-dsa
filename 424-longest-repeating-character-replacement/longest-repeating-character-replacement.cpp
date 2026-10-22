class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        int maxfreq = 0;
        unordered_map<char, int> mpp;
        while (r < n) {
            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);
            while ((r - l + 1) - maxfreq > k) {
                mpp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};