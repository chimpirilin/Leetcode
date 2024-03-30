typedef long long ll;

// https://leetcode.com/problems/find-the-divisibility-array-of-a-string/
class Solution {
public:
    ll mod = 0;
    vector<int> divisibilityArray(string word, int m) {
        mod = static_cast<long long>(m);
        vector<ll> modVec;
        ll cur = stoll(word.substr(0,1)) % mod;
        modVec.push_back(cur);
        int n = word.size();
        for(int i=1;i<n;++i){
            ll cur = stoll(word.substr(i,1)) % mod;
            ll pow = (10LL*modVec[i-1])%mod;
            ll res = (pow+cur)%mod;
            modVec.push_back(res);
        }
        vector<int> ans;
        for(auto x:modVec){
            if(x == 0) ans.push_back(1);
            else ans.push_back(0);
        }

        return ans;
    }
};