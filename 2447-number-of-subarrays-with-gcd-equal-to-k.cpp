// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count  = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int g = nums[i];
            for(int j = i; j < len; j++){
                g = __gcd(g, nums[j]);
                count = (g == k ? count + 1 : count);
            }    
        }      
        return count;  
    }
};

int main(){

    return 0;
}