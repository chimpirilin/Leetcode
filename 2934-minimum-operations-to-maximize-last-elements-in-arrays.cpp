// https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/
class Solution {
public:

    bool validArray(vector<int>& nums) {
        return nums.back() == *max_element(nums.begin(), nums.end());
    }

    bool valid(vector<int>& nums1, vector<int>& nums2) {
        return validArray(nums1) && validArray(nums2);
    }

    int solve(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size();

        int cnt = 0;
        int last1 = nums1.back();
        int last2 = nums2.back();
        if(valid(nums1, nums2)) return 0;

        for(int i = 0; i < n - 1; i++){
            if(nums2[i] == last2) {
                if(nums1[i] > last1 && nums2[i] <= last1 && nums1[i] <= last2) {
                    swap(nums2[i], nums1[i]);
                    cnt++;
                }
            } else if(nums2[i] > last2) {
                swap(nums2[i], nums1[i]);
                cnt++;
            }
        }

        if(valid(nums1, nums2)) return cnt;
        else return 1000000;

    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int res1 = solve(nums1, nums2);
        int res2 = solve(nums2, nums1);
        swap(nums2[n-1], nums1[n-1]);
        int res3 = solve(nums1, nums2) + 1;
        int res4 = solve(nums2, nums1) + 1;
        int mn = min({res1, res2, res3, res4});
        int ans =  (mn < 1000000 ? mn : -1);
        return ans;
    }
};