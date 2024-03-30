// https://leetcode.com/problems/substring-xor-queries/
class Solution {
public: 
    string toBinary(int x){
        if(x==0) return "0";
        string ans="";
        while(x>0){
            if(x%2==0) ans+="0";
            else ans+="1";
            x/=2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<string, int> candidates;
        for(int i=0;i<s.size();++i){
            for(int j=1;j<=31;++j){
                string st="";
                if(i+j>s.size()) break;
                for(int k=i;k<i+j;++k){
                    st+=s[k];
                }
                auto it = candidates.find(st);
                if(it==candidates.end()) candidates[st] = i;
            }
        }
        vector<vector<int>> ans;
        vector<int> notFound = {-1,-1};
        for(auto q:queries) {
            int xored = q[0]^q[1];
            string val = toBinary(xored);
            auto it = candidates.find(val);
            if(it==candidates.end()) ans.push_back(notFound);
            else{
                int pos = it->second;
                int last = pos+val.size()-1;
                vector<int> found = {pos,last};
                ans.push_back(found);
            }
        }
        return ans;
    }
};