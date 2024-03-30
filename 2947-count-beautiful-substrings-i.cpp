// https://leetcode.com/problems/count-beautiful-substrings-i/
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int v = 0, c = 0;
            for(int j = 0; j < n; j++) {
                int idx = i+j;
                if(idx >= n) break;
                if(s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u') {
                    v++;
                } else c++;
                if((c == v)&&(c*v)%k == 0) ans++;
            }   
        }

        return ans;
    }
};