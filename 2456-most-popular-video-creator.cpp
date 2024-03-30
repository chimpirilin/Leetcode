// https://leetcode.com/problems/most-popular-video-creator/
class Solution {
public:

    // custom comparator
    struct Compare
    {
        bool operator()(const pair<int, string>& firstPair, const pair<int, string>& secondPair) const
        {
            if(firstPair.first == secondPair.first) return firstPair.second > secondPair.second;
            return firstPair.first < secondPair.first;
        }
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        map<string, long long> viewcount;
        
        
        map<string, set<pair<int, string>, Compare>> videos;
        long long maxviews=0;
        for(int i=0;i<n;++i){
            viewcount[creators[i]]+=views[i];
            pair<int,string> p = make_pair(views[i],ids[i]);
            videos[creators[i]].insert(make_pair(views[i],ids[i]));
            maxviews=max(maxviews, viewcount[creators[i]]);
        }
        vector<vector<string>> ans;
        for(auto x:viewcount){
            if(x.second == maxviews){
                vector<string> v;
                v.push_back(x.first);
                string highestview = videos[x.first].rbegin()->second;
                v.push_back(highestview);
                ans.push_back(v);
            }
        }
        return ans;
    }
};