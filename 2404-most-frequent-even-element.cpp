// https://leetcode.com/problems/most-frequent-even-element/
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int rep=0;
        int num=-1;
        vector<int> freq(100005,0);
        for(auto x: nums){
            ++freq[x];
        }
        F(i,0,100005,2){
            if(freq[i]>rep){
                rep=freq[i];
                num=i;
            }
        }
        return num;
    }
};
