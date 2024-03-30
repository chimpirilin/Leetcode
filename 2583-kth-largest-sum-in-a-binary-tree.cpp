/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
class Solution {

public:
    map<int, long long> levelSum;

    void computeSum(TreeNode *node, int level){
        long long val = static_cast<long long>(node->val);
        levelSum[level] += val;
        // cout<<node->val<< " "<<level<<" "<<levelSum[level]<<endl;
        if(node->left != nullptr) computeSum(node->left, level+1);
        if(node->right != nullptr) computeSum(node->right, level+1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        computeSum(root, 1);
        vector<long long> sortedLevels;
        for (auto [x, y]:levelSum){
            sortedLevels.push_back(y);
        }
        sort(sortedLevels.rbegin(), sortedLevels.rend());
        // for(auto s: sortedLevels) cout<<s<<" ";
        // cout<<endl;
        if(k>sortedLevels.size()) return -1;
        return sortedLevels[k-1];
    }
};
