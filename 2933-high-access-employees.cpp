// https://leetcode.com/problems/high-access-employees/
class Solution {
public:
    // Create a map to store the access times in increasing order of a user
    // then run a sliding window and substract the ith and (i+2)th and check
    // if they are within the 60 minutes period.
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        map<string, vector<string>> m;
        
        for(auto v:access_times) {
            m[v[0]].push_back(v[1]);
        }

        for(auto &val:m) {
            auto &vec = val.second;
            sort(vec.begin(),vec.end());
        }
        
        for(auto val:m) {
            auto vec = val.second;
            for(int i = 0; i < (int)vec.size() - 2; i++) {
                if(stoi(vec[i+2]) -stoi(vec[i]) < 100) {
                    ans.push_back(val.first);
                    break;
                }
            }
        }

        return ans;
    }
};