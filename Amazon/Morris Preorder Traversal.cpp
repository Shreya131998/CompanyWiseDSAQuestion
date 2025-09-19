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
		vector<int> preorder(TreeNode* root){
	       //your code goes here
           vector<int>ans;
           TreeNode* temp = root;
           while(temp){
                if(temp->left==NULL){
                    ans.push_back(temp->data);
                    temp = temp->right;
                }
                else{
                    
                    TreeNode* prev = temp->left;
                    while(prev->right!=temp && prev->right){
                        prev = prev->right;
                    }
                    if(prev->right==NULL){
                        prev->right = temp;
                        ans.push_back(temp->data);
                        temp = temp->left;
                    }
                    else{
                        // ans.push_back(prev->right->data);
                        prev->right = NULL;
                        temp = temp->right;
                    }
                }
           }
           return ans;
		}
};