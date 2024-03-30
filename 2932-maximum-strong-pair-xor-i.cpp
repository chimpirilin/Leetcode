// https://leetcode.com/problems/maximum-strong-pair-xor-i/
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
            int maximum = -1;
            for(auto val1:nums) {
                for(auto val2:nums) {
                    if(abs(val1-val2) <= min(val1, val2) && (val1^val2) > maximum) {
                        maximum = val1^val2;
                    }
                }
            }
        return maximum;
    }
};