// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
class Solution {
public:
    int appendCharacters(string s, string t) {
        map<char, set<int>> m;
        for(int i=0;i<s.size();++i){
            char x = s[i];
            m[x].insert(i);
        }

        int lastIndex = 0;
        int ans = t.size();
        for(auto x: t){
            if(m[x].empty()) break;
            auto it = m[x].lower_bound(lastIndex);
            if(it == m[x].end()) break;
            int curIndex = *it;
            m[x].erase(it);
            if(curIndex < lastIndex) break;
            lastIndex = curIndex;
            --ans;
        }
        return ans;
    }
};