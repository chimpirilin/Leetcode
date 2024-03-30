// https://leetcode.com/problems/find-the-maximum-divisibility-score/
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(), divisors.end());
        int maxScore = 0, ans = divisors[0];

        for(int i = 0; i < divisors.size(); i++){
            int x = divisors[i];
            int cur = 0;
            for(auto y:nums){
                if(y%x == 0){
                    ++cur;
                }
            }
            if(cur>maxScore){
                maxScore = cur;
                ans = x;
            }
        }            
        return ans;
    }
};