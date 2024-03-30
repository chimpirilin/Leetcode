// https://leetcode.com/problems/make-three-strings-equal/description/
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = min({s1.size(), s2.size(), s3.size()});
        int m = max({s1.size(), s2.size(), s3.size()});

        bool impossible = true;
        int mn = 0;

        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[i] && s2[i] == s3[i]) {
                mn++;
                impossible = false;
            }else break;
        }

        int ans = (int)s1.size() - mn + (int)s2.size() - mn + (int)s3.size() - mn;
        if(impossible) return -1;
        return ans;
    }
};