// https://leetcode.com/problems/separate-black-and-white-balls/
class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0;
        long long ans = 0;
        for(auto c:s) {
            if(c == '1') {
                ones++;
            }else {
                ans += ones;
            }
        }
        return ans;
    }
};