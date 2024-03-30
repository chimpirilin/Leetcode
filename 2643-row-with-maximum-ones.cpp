// https://leetcode.com/problems/row-with-maximum-ones/
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<int> ans{0, 0};

        for(int i = 0; i < n; ++i){
            int cur = 0;
            for(auto x:mat[i]){
                cur += x;
            }
            if(cur > ans[1]){
                ans[0] = i;
                ans[1]= cur;
            }
        }
        return ans;
    }
};