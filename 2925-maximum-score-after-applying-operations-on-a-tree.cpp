#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree
class Solution {
public:

    vector<vector<int>> adjacencyList;
    vector<vector<long long>> dp;
    vector<long long> vals;
    int n;

    /*
        dp on tree problem, two choices: exclude current's node or not (knapsack 0/1-like dp)
        we exclude a node to ensure healthy property of the tree
    */
    long long solve(int node, bool picked, int par) {
        auto &ref = dp[node][picked];

        if(ref != -1) return ref;

        long long result = 0LL;

        // a leaf
        if(adjacencyList[node].size() == 1 && par != -1) {
            
            if(picked) {
                // if a previous value was picked to not be included, then you can just use the value of the leaf
                result = vals[node];
            }else {
                // if a previous value was not picked to be included, then you must pick this one to not be included
                // thus you can't use its value, this is the one not picked to ensure healthy property
                result = 0LL;
            }
            return ref = result;

        }

        // if a previous value was picked to not be included, then you can use the sum of all 
        // the values of this subtree so just return the sum of the subtree
        if (picked) { 
            for(auto child : adjacencyList[node]) {
                if (child == par) continue;
                result += solve(child, true, node);
            }
            // add the value of current node but only after we are done summing the subtrees
            // otherwise we will double count its value.
            result += vals[node];
            return ref = result;
        }

        long long res1 = 0, res2 = 0;

        // None node has been picked, so you have two choices to pick this node or not

        // in this case, we will choose not to pick so you can sum current's node value
        for(auto child : adjacencyList[node]) {
            if (child == par) continue;
            res1 += solve(child, false, node);
        }
        // again, sum it here to avoid overcounting
        // sounds obvious but it took some time to realize that :/
        res1 += vals[node];

        // pick this node, so we won't add this node values, since we chose it to no be included
        for(auto child : adjacencyList[node]) {
            if(child == par) continue;
            res2 += solve(child, true, node);
        }
        result = max(res1, res2);
        return ref = result;
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        
        n = edges.size() + 1;
        vals.resize(n);
        for(int i = 0; i < n; i++) {
            vals[i] = static_cast<long long>(values[i]);
        }
        adjacencyList.resize(n);
        dp.resize(n);
        vector<long long> v(2);
        for(int i = 0; i < n; i++) {
            dp[i] = v;
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        for(auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        long long ans = solve(0, false, -1);
        return ans;
    }
};

int main() {

    vector<vector<int>> edges;

    edges.push_back(vector<int>{0, 1});
    edges.push_back(vector<int>{0, 2});
    edges.push_back(vector<int>{0, 3});
    edges.push_back(vector<int>{2, 4});
    edges.push_back(vector<int>{4, 5});
    vector<int> values{5, 2, 5, 2, 1, 1};
    Solution s;
    long long ans = s.maximumScoreAfterOperations(edges, values);
    assert(ans == 11);
    cout << ans << endl;
    return 0;
}