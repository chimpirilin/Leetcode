// https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        long long kk = static_cast<long long>(k);
        int ans=0;
        for(int i=0;i<n;++i){
            long long l = static_cast<long long>(nums[i]);
            for(int j=i;j<n;++j){
                l = lcm(l, nums[j]);
                if(l == kk) ++ans;
                if(l>kk) break;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}