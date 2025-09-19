// Given the root of a binary tree and two integers p and q, return the distance between the two nodes with values p and q.



// The distance between two nodes in a tree is the number of edges on the shortest path between them.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(val) : data(val), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, int p, int q){
        if(!root)return NULL;
        if(root->data ==p || root->data==q){
            return root;
        }
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
        if(left && right){
            return root;
        }
        else if(left && !right){
            return left;
        }
        else if(!left && right){
            return right;
        }
        else{
            return NULL;
        }
    }
    int getDist(TreeNode* root, int p){
        if(!root)return -1;
        if(root->data==p){
            return 0;
        }
        int left = getDist(root->left,p);
        if(left!=-1)return left+1;
        int right = getDist(root->right,p);
        if(right!=-1)return right+1;
        return -1;
    }
    int findDistance(TreeNode* root, int p, int q) {
        //Your Code Goes Here
        TreeNode* node= lca(root,p,q);
        // cout<<node->data<<endl;
        int l = getDist(node,p);
        int r = getDist(node,q);
        // cout<<l<<" "<<r;
        return (l+r);
    }
};