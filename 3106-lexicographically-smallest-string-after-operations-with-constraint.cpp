// https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/
class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string ans = s;
        for(int i = 0; i < n; i++) {
            // Greedy: find what's cheaper between the two directions.
            // { is the character after z, we use it to get the distanceto the right
            int best = min('{'-s[i],s[i]-'a');

            // we don't have enough movements to go to a so just pick the best you can.
            if(best > k) {  
                ans[i] = static_cast<char>(s[i]-k);
                k = 0;
            } else { // enough movements to go to a.
                ans[i] = 'a';
                k -= best;
            }
        }

        return ans;
    }
};