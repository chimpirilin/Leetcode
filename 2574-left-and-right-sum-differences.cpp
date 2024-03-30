// https://leetcode.com/problems/left-and-right-sum-differences/
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int cur = 0;
        vector<int> leftsum = {0};
        vector<int> rightsum = {0};
        vector<int> ans;
        for(auto x: nums){
            cur+=x;
            leftsum.push_back(cur);
        }
        cur = 0;
        reverse(nums.begin(), nums.end());
        for(auto x: nums){
            cur+=x;
            rightsum.push_back(cur);
        }
        leftsum.pop_back();
        rightsum.pop_back();
        reverse(rightsum.begin(), rightsum.end());
        for(int i=0;i<rightsum.size();++i) ans.push_back(abs(leftsum[i]-rightsum[i]));
        return ans;
    }
};