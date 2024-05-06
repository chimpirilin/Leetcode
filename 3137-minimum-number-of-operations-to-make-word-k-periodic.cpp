https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/
class Solution {
public::

    // Greedy: use the most frequent substring of length k (starting at index divisible by k)
    // the most frequent susbstring comes for free, the rest of the substrings need to be changed
    // thus we substract the most frequent substring from the total number of substrings.
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int  n = word.size();
        map<string, int> m;
        string subs = "";
        for(int i = 0; i < n; i++) {
            subs += word[i];
            if(i%k==k-1) {
                m[subs]++;
                subs = "";
            }
            
        }
        string mostFrequent = "";
        int curMax = 0;
        for(auto [key, value] : m) {
            if(value > curMax) {
                mostFrequent = key;
                curMax = value;
            }
        }
        int ans = n/k - curMax;
        return ans;
    }
};