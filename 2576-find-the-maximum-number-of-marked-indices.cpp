// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/ 
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), idx = n/2 - 1, lastidx = n-1,  pairs=0;
        for(;idx>=0;--idx) if(nums[idx]*2<=nums[lastidx]) ++pairs, --lastidx;
        return pairs*2;
    }
};