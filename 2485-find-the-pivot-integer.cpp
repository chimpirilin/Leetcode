// https://leetcode.com/problems/find-the-pivot-integer/
class Solution {
public:
    int pivotInteger(int n) {
        int ans = -1;
        int sm = (n*(n+1))/2;
        for(int i=1; i<=n;++i){ 
            int sm1 = (i*(i+1))/2;
            int sm2 = sm-sm1+i;
            if(sm1==sm2){
                ans=i;
                break;
            }
        }
        return ans;
    }
};