// https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/
class Solution {
    public:
        // Greedy: get the median of original array and try to increase/decrease numbers
        // until we get k. Once we modify the original median to be k, the left or right half
        // needs to be modified to so that k is the median
        // example: [2, 5, 5, 6, 8], k = 4
        // let's change the median to be 4: [2, 5, 4, 6, 8], but if we sort it, 5 is the median.
        // so remaining 5 needs to be modified: [2, 4, 4, 6, 8], now 4 is the median.
        // no need to modify 2 since it won't make any difference in the median (nums[i] > k condition)
        long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
            long long ans = 0;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int i = n/2;
            // operate on the left half of the array
            
            while(nums[i] > k) {
                // we add nums[i] - k since that's the number we need to add nums[i] > k to be k
                // note that making nums[i] smaller than k could satisfy the condition of k being the median
                // but we would need extra operations and we want the minimum number of operations so let's 
                // not do that, hence the condition nums[i] > k. Same logic applies to the while
                ans += static_cast<long long>(nums[i] - k);
                i--;
                if(i == -1) break;
            }
            i = n/2;

            // operate on the right half of the array
            while(nums[i] < k) {
                // we add k - nums[i] since that's the number we need to add nums[i] to be k
                ans += static_cast<long long>(k - nums[i]);
                i++;
                if(i == n) break;
            }

            return ans;
        }
    };