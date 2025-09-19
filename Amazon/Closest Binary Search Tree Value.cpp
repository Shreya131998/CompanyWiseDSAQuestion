// Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target. If there are multiple answers, return the smallest one.

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/

class Solution {
public:
    double diff = INT_MAX;
    int number = -1;
    void solve(TreeNode* root, double target){
        if(!root)return;
        if(diff> abs(root->val-target)){
            diff = abs(root->val-target);
            number = root->val;
        }
        else if(diff== abs(root->val-target)){
            number = min(number, root->val);
        }
        if(root->val>target){
            solve(root->left,target);
        }
        else{
            solve(root->right,target);
        }
    }
    int closestValue(TreeNode* root, double target) {
        // Your code goes here
        solve(root,target);
        return number;
    }
};