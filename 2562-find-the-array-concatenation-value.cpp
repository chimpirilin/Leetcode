// https://leetcode.com/problems/find-the-array-concatenation-value/
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0, j = nums.size()-1,  n = (nums.size() +1)/2;
        long long ans = 0;
        while(n--){
            string a = to_string(nums[i]);
            string b = to_string(nums[j]);
            if(i == j) b = "";
            a+=b;
            long long res = stoll(a);
            ans += res;
            ++i;
            --j;
        }
        return ans;
    }
};