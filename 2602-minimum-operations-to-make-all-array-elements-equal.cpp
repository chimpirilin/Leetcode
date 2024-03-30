// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> ans;
        long long s=0;
        long long n = static_cast<long long>(nums.size());
        vector<long long> partial(n+1);
        partial[0] = 0LL;
        for (int i = 0; i < n; i++) {
            partial[i+1] = partial[i] + static_cast<long long>(nums[i]);
        }
        
        for(auto x:queries){
            long long p = static_cast<long long>(upper_bound(nums.begin(), nums.end(), x) - nums.begin());

            long long np = n-p;
            long long curx = static_cast<long long>(x);
            long long res = -1LL*partial[p]+curx*p+(partial[n]-partial[p])+np*curx*-1LL;
            ans.push_back(res);
        }
        return ans;
    }
};
