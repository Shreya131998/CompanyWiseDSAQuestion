// Given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.Recover the tree without changing its structure.


// Examples:
// Input : root = [1, 3, null, null, 2]

// Output : [3, 1, null, null, 2]

// Explanation : 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void solve(TreeNode* root){
        if(!root)return;
        solve(root->left);
        if(prev && prev->data>root->data){
            if(!first){
                first = prev;
            }
            second = root;
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
       //your code goes here
       solve(root);
       if(first && second){
        swap(first->data,second->data);
       }
    }
};