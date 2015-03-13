class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, ct = 0;
        int mp[256] = {0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]]++ == 0) cnt++;
            while (ct > 2) {
                mp[s[start]]--;
                if (mp[s[start++]] == 0) ct--;
            }
            ans = max(i - start + 1, ans);
        }
        return ans;
    }
};