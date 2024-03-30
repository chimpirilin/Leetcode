// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
class Solution {
public:

    bool visited[20][20];

    vector<vector<int>> g;
    int n, m;

    int dirx[4]{-1, 0, 1, 0};
    int diry[4]{0, 1, 0, -1};

    int dirSize = 4;

    bool isValidPosition(int posx, int posy) { 
        if(posx < 0 || posy < 0 || posx >= n || posy >= m || g[posx][posy] == 0) return false;
        return true;
    }

    int dfs(int posx, int posy) { 
        if(visited[posx][posy]) return 0;
        visited[posx][posy] = true;

        int val = g[posx][posy];

        for(int i = 0; i < dirSize; i++) {
            int nposx = posx + dirx[i];
            int nposy = posy + diry[i];
            if(!isValidPosition(nposx, nposy)) continue;
            val += dfs(nposx, nposy);
        }
        return val;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        g = grid;
        n = int(g.size());
        m = int(g[0].size());

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 0) continue;
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};