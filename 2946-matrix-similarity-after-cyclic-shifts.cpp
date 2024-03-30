// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> shifted(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                shifted[i][j] = mat[i][j];
            }
        }

        for (int i = 0; i < rows; ++i) {
            if(i%2!=0) {
                // shift right
                int start = ((cols-k)%cols+cols)%cols;
                for (int idx = start, cnt = 0; cnt < cols; idx = (idx+1)%cols, cnt++) {
                    shifted[i][cnt] = mat[i][idx];
                }
            }else {
                // shift left
                int start = k%cols;
                for (int idx = start, cnt = 0; cnt < cols; idx = (idx+1)%cols,cnt++) {
                    shifted[i][cnt] = mat[i][idx];
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(shifted[i][j] != mat[i][j]) return false;
            }
        }

        return true;
    }
};