// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
class Solution {
public:
    set<pair<pair<int,int>, int>> v;
    map<pair<int, int>, int> m;

    void searching(int val){
        auto p = make_pair(make_pair(val, 0), 0);
        auto it=v.lower_bound(p);

        if(it==v.end()) return;
        int lookfor=(*it).first.second+1;
        v.erase(it);
        searching(lookfor);
    }

    int minGroups(vector<vector<int>>& intervals) {
        for(int i=0;i<intervals.size();++i){
            auto p = make_pair(intervals[i][0], intervals[i][1]);
            v.insert(make_pair(p,m[p]++));
        }
        auto it = v.begin();
        int ans=0;
        while(it!=v.end()){
            it = v.begin();
            int lookfor=(*it).first.second+1;
            v.erase(it);
            searching(lookfor);
            ++ans;
        }
        return ans;
    }
};
