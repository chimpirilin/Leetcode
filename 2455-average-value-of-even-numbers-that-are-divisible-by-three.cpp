// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sm=0;
        int n = 0;
        for(auto x:nums) if(x%6==0) sm+=x, ++n;
        if(n==0) return 0;
        return sm/n;
    }
};