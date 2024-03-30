#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<int, vector<int>> m;
    int level[100005];
    TreeNode *tree[100005];
    
    void bfs(TreeNode *root){
        queue<int> q;
        q.push(root->val);
        level[root->val] = 0;

        while(!q.empty()){
            auto nodeVal = q.front();
            q.pop();
            int l = level[nodeVal]+1;
            auto node = tree[nodeVal];
            if(node->left != nullptr){
                int lval = node->left->val;
                m[l].push_back(lval);
                level[lval] = l;
                q.push(lval);
            }
            if(node->right != nullptr){
                int rval = node->right->val;
                m[l].push_back(rval);
                level[rval] = l;
                q.push(rval);
            }
        }
    }

    void dfs(TreeNode *node){
        tree[node->val] = node;
        if(node->right != nullptr) dfs(node->right);
        if(node->left != nullptr) dfs(node->left);
    }

    int minimumOperations(TreeNode* root) {
        dfs(root);
        bfs(root);
        int ans = 0;
        
        for(auto x:m){
            auto v = x.second;
            map<int, int> pos;
            for(int i=0;i<v.size();++i){
                pos[v[i]] = i;
            }
            sort(v.begin(), v.end());
            for(int i=0;i<v.size();++i){
                if(pos[v[i]] != i){
                    ++ans;
                    swap(x.second[i], x.second[pos[v[i]]]);
                    pos[x.second[pos[v[i]]]] = pos[v[i]];
                }
            }
        }
        return ans;
    }
};


void dfs(TreeNode *node){
    //tree[node->val] = node;
    cout<<node->val<<endl;
    if(node->left != nullptr) dfs(node->left);
    if(node->right != nullptr) dfs(node->right);
}

int main(){
    // cin>>n;
    //vector<int> v(n);
    vector<int> v{49,45,1,20,46,15,39,27,-1,-1,-1,25};
    int n = v.size();
    vector<TreeNode*> nodes(n);
    TreeNode *root =  new TreeNode(v[0]);
    nodes[0] = root;
    for(int i=0;i<n;++i){
        int l = i*2+1, r = i*2+2;
        TreeNode *cur = nodes[i];
        if(cur == nullptr) continue;

        if(l>=n) break;

        TreeNode *lnode = nullptr;
        if(v[l] != -1) lnode = new TreeNode(v[l]);
        if(r>=n) break;
        TreeNode *rnode = nullptr;
        if(v[r] != -1) rnode = new TreeNode(v[r]);
        cur->left = lnode;
        cur->right = rnode;
        nodes[l] = lnode;
        nodes[r] = rnode;
    }
    dfs(root);
    Solution s;
    cout<<s.minimumOperations(root)<<endl;
}