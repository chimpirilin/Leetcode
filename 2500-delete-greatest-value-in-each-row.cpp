// https://leetcode.com/problems/delete-greatest-value-in-each-row/
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;++i){
            sort(grid[i].begin(), grid[i].end());
            reverse(grid[i].begin(), grid[i].end());
        }
        int ans = 0;
        for(int i=0;i<m;++i){
            int cur = 0;
            for(int j=0;j<n;++j){
                cur = max(cur,grid[j][i]);
            }
            ans+=cur;
        }

        return ans;
    }
};