// https://leetcode.com/problems/find-champion-ii/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        int cnt = 0;
        int winner = -1;

        vector<bool> in(n, false);
        for(auto el:edges) {
            in[el[1]] = true;
        }

        for(int i = 0; i < n; ++i) {
            if(!in[i]) {
                cnt++;
                winner = i;
            }
        }
        if(cnt > 1) winner = -1;

        return winner;
    }
};