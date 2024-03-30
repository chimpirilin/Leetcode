// https://leetcode.com/problems/increment-submatrices-by-one/
    class Solution {
    public:
        vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
            vector<vector<int>> mat(n, vector<int>(n+4));
            vector<vector<int>> d(n, vector<int>(n+4));
            vector<vector<int>> ans(n, vector<int>(n));
            for (auto q:queries){
                int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
                ++c1, ++c2;
                for(int i = r1; i<=r2;++i){
                    d[i][c1] += 1;
                    d[i][c2+1] -= 1; 
                }
            }
            for(int i=0;i<n;++i){
                for(int j=1;j<=n;++j){
                    mat[i][j] = d[i][j]+mat[i][j-1];
                }
            }
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    ans[i][j] = mat[i][j+1];
                }
            }
            return ans;
        }
    };