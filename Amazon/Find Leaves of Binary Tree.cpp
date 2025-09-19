// Given the root of a binary tree, collect a tree's nodes as if you were doing this:

// Collect all the leaf nodes.
// Remove all the leaf nodes.
// Repeat until the tree is empty

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
class Solution {
public:
    int solve(TreeNode* root,map<int,unordered_set<int>>&m){
        if(!root)return 0;
        int l = solve(root->left,m);
        int r = solve(root->right,m);
        int h = max(l,r)+1;
        m[h].insert(root->val);
        return h;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        // Your code goes here
        vector<vector<int>>ans;
        map<int,unordered_set<int>>m;
        solve(root,m);
        for(auto i: m){
            vector<int>v;
            auto t = i.second;
            v.insert(v.end(),t.begin(),t.end());
            ans.push_back(v);
        }
        return ans;

    }
};