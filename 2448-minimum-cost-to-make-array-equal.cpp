// https://leetcode.com/problems/minimum-cost-to-make-array-equal/
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<long long,long long> > v;
        for(int i=0;i<nums.size();++i){
            v.push_back(make_pair(static_cast<long long>(nums[i]), static_cast<long long>(cost[i])));
        }
        sort(v.begin(), v.end());
        vector<long long> costTimesNums(v.size()+1, 0LL);
        vector<long long> costSum(v.size()+1, 0LL);

        for(int i=1;i<costTimesNums.size();++i){
            costTimesNums[i] = costTimesNums[i-1]+v[i-1].first*v[i-1].second;
            costSum[i] = costSum[i-1]+v[i-1].second;
        }
        long long ans = 1e18;
        for(int i=0;i<v.size();++i){
            ll cur = v[i].first*(costSum[i+1])-v[i].first*(costSum[static_cast<int>(costSum.size())-1]-costSum[i+1]);
            cur += -costTimesNums[i+1]+(costTimesNums[static_cast<int>(costTimesNums.size())-1]-costTimesNums[i+1]);
            ans = min(ans, cur);
        }
        return ans;
    }
};