/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {	
public:
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if(!root)return 0;
        // we will ignore the min values so chcking with max(0,call())
        int left = max(0,solve(root->left));
        int right = max(0,solve(root->right));
        int sum = left+right+root->data;
        int curr = root->data;
        maxi = max(maxi,sum);
        return curr+ max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        //your code goes here
        if(root->left==NULL && root->right==NULL)return root->data;
        solve(root);
        return maxi;
    }
};	