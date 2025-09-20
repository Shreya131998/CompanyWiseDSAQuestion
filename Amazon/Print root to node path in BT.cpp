/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
        void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>v){
            if(!root)return;
            if(root->left==NULL && root->right==NULL){
                v.push_back(root->data);
                ans.push_back(v);
                return;
            }
            v.push_back(root->data);
            solve(root->left,ans,v);
            solve(root->right,ans,v);
        }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>>ans;
            vector<int>v;
            solve(root,ans,v);
            return ans;
		}
};