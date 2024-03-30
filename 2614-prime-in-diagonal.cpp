bool isprime(int x){
    if(x == 1) return false;
    if(x == 2) return true;
    int lim = sqrt(x)+1;
    // cout<<sqrt(x)<<" "<<lim<<endl;
    for (int i = 2; i <=lim; i++)
    {
        if(x%i==0) return false;
    }
    return true;
    
}

// https://leetcode.com/problems/prime-in-diagonal/
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = (int)nums.size();
        int m = (int)nums[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if((i==j || i+j==n-1)){
                    if(isprime(nums[i][j])&&nums[i][j]>ans)
                        ans = nums[i][j];
                }
            }
        }

        return ans;
            
    }
};