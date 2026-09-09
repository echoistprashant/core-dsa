class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {

            unordered_map<char, int> mp;

            for(int j = i; j < n; j++) {

                mp[s[j]]++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for(auto &p : mp) {
                    maxFreq = max(maxFreq, p.second);
                    minFreq = min(minFreq, p.second);
                }

                ans += maxFreq - minFreq;
            }
        }

        return ans;
    }
};