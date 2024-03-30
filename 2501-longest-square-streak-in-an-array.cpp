// https://leetcode.com/problems/longest-square-streak-in-an-array/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<long long, int> nxt;
        int ans=-1;
        for(int i=0;i<nums.size();++i){
            int x = nums[i];
            long long newkey  = static_cast<long long>(x);
            newkey = newkey*newkey;
            if(nxt.find(x) != nxt.end()){
                nxt[newkey] = nxt[x]+1;
                ans = max(ans, nxt[x]);
            }else{
                nxt[newkey] = 2;
                ans = max(ans, 1);
            }
        }
        return ans>1? ans : -1;
    }
};