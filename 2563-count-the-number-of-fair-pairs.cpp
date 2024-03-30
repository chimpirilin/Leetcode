// https://leetcode.com/problems/count-the-number-of-fair-pairs/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0LL;
        int i=1;
        for(auto x:nums){
            long long l = static_cast<long long>(lower_bound(nums.begin()+i, nums.end(), lower-x) - nums.begin());
            long long r = static_cast<long long>(upper_bound(nums.begin()+i, nums.end(), upper-x) - nums.begin());
            ans+=r-l;
            ++i;
        }
        return ans;
    }
};