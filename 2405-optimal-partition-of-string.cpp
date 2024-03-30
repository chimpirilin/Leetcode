// https://leetcode.com/problems/optimal-partition-of-string/
class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(256);
        fill(freq.begin(), freq.end(),0);
        int cnt=1;
        for(auto x: s){
            int ascii = (int)x;
            if(freq[ascii] > 0){
                ++cnt;
                fill(freq.begin(), freq.end(),0);
            }else{
                freq[ascii]=1;
            }
        }
        return cnt;
    }
};