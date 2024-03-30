// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int s1 = 0, s2=0;
        for(auto &x: nums){
            s1 += x;

            while(x > 0){
                int d = x%10;
                s2 += d;
                x /= 10;
            }
        }
        return abs(s1-s2);
    }
};