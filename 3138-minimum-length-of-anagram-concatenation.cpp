https://leetcode.com/problems/minimum-length-of-anagram-concatenation/
class Solution {
public:
    // s is the concatenation of n anagrams of t, let's denote ti and si as the frequency of the
    // ith character in t and s respectevely. thus |t| = t1+t2+...+tm and 
    // |s| = n*t1+n*t2+...+n*tm = n*(t1+t2+...+tm) = s1+s1+...+sp.
    // In other words we need to find a divisor that's common to s1, s2, ..., sp and we want the divisor
    // t be the greatest among all divisors to minimize the length of string t (n/d is minimized when d is maximized).
    // Thus, we ought to find the gcd of s1, s2, ..., sp. the final answer is to divide each s1 by the gcd which
    // will give you the actual occurence of si in t, that is, ti.
    int minAnagramLength(string s) {
        int n = s.size();

        map<char, int> m;

        for(auto c : s) {
            m[c]++;
        }

        int minimum = 1e9;
        int g = -1;
        for(auto [key, value] : m) {
            if(value < minimum) {
                minimum = value;
            }
            if(g == -1) {
                g = value;
            } else {
                g = __gcd(g, value);
            }
        }

        int ans = 0;
        for(auto [key, value] : m) {
            ans += value/g;
        }

        return ans;
    }
};