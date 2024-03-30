// https://leetcode.com/problems/sum-of-distances/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans;
        map<int, vector<pair<long long, long long> > > hashtable;
        map<int, int> nums2hashtable;
        for (int i = 0; i < (int)nums.size(); i++){
            if(hashtable[nums[i]].size() == 0){
                //dummy value to simplify cumulative sum logic
                hashtable[nums[i]].push_back(make_pair(0, 0));
            }
            long long last = hashtable[nums[i]].back().second;
            hashtable[nums[i]].push_back(make_pair(i, last+i));
            nums2hashtable[i] = ((int)hashtable[nums[i]].size())-1;
        }   
        for (int i = 0; i < (int)nums.size(); i++){
            long long res = 0LL;
            res += static_cast<long long>(nums2hashtable[i]-1)*i;
            res -= static_cast<long long>(((int)hashtable[nums[i]].size()-1)-nums2hashtable[i])*i;
            res -= hashtable[nums[i]][nums2hashtable[i]-1].second;
            res += hashtable[nums[i]].back().second-hashtable[nums[i]][nums2hashtable[i]].second;
            ans.push_back(res);
        }
        return ans;
    }
};