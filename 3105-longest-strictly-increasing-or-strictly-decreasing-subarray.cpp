// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
class Solution {
public:

    int longestIncreasing(vector<int> &nums) {
        int mx = 1;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int cur = 1;
            for(int j=i+1; j<n; j++) {
                if(nums[j] > nums[j-1]) cur++;
                else break;
            }
            mx = max(mx, cur);
        }

        return mx;
    }

    int longestDecreasing(vector<int> &nums) {
        int mx = 1;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int cur = 1;
            for(int j=i+1; j<n; j++) {
                if(nums[j] < nums[j-1]) cur++;
                else break;
            }
            mx = max(mx, cur);
        }

        return mx;
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = max(longestIncreasing(nums), longestDecreasing(nums));
        return ans;
    }
};