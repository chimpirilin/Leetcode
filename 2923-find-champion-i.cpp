// https://leetcode.com/problems/find-champion-i/
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int winner = -1;
        int n = grid.size();
        for(int j = 0; j < n; j++) {
            // bool win = true;
            int cnt = 0;
            for(int k = 0; k < n; k++) {
                if (k == j) continue;
                cnt += grid[j][k];
            }
            if(cnt == n-1) {
                winner = j;
            }

        }

        return winner;
    }
};