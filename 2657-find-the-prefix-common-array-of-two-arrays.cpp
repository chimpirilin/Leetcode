// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // n <= 50, just brute force

        vector<int> ans;

        int n = A.size();

        set<int> setA, setB;

        int cnt = 0;

        for(int i = 0; i < n; i++){
            int valA = A[i], valB = B[i];

            setA.insert(valA);
            setB.insert(valB);

            if(setB.count(valA) > 0) ++cnt;
            if(setA.count(valB) > 0) ++cnt;

            if(valA == valB) --cnt;

            ans.push_back(cnt);
        }

        return ans;

    }
};