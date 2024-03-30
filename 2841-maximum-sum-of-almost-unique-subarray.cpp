// https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        deque<int> d;
        map<int, int> hTable;
        int uniques = 0;
        long long curSum = 0;
        long long maxSum = 0;

        for(int i = 0; i < k; i++) {
            d.push_back(nums[i]);
            curSum += static_cast<long long>(nums[i]);
            if(hTable.find(nums[i]) == hTable.end())
                uniques++;
            hTable[nums[i]]++;
        }

        if(uniques >= m) maxSum = curSum;

        for(int i = k; i < nums.size(); i++) {
            int front = d.front();
            d.pop_front();
            hTable[front]--;
            if (hTable[front] == 0) uniques--;
            curSum -= static_cast<long long>(front);
            curSum += static_cast<long long>(nums[i]);
            d.push_back(nums[i]);
            if(hTable.find(nums[i]) == hTable.end() || hTable[nums[i]] == 0)
                uniques++;
            hTable[nums[i]]++;

            if(uniques >= m) maxSum = max(curSum, maxSum);
        }

        return maxSum;
    }
};