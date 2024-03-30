// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(k--){
            ans+=mx;
            ++mx;
        }
        return ans;
    }
};