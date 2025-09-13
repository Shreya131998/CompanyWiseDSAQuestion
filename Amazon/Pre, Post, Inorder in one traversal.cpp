// Given a binary tree with root node. Return the In-order,Pre-order and Post-order traversal of the binary tree.

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
		vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
            vector<int>pre,in,post;
            vector<vector<int>>ans;
            stack<pair<TreeNode*,int>>s;
            s.push({root,1});
            while(!s.empty()){
                auto top = s.top();
                int state = top.second;
                auto fNode = top.first;
                s.pop();
                if(state==1){
                    pre.push_back(fNode->data);
                    s.push({fNode,2});
                    if(fNode->left){
                        s.push({fNode->left,1});
                    }
                }
                else if(state==2){
                    in.push_back(fNode->data);
                    s.push({fNode,3});
                    if(fNode->right){
                        s.push({fNode->right,1});
                    }
                }
                else{
                    post.push_back(fNode->data);
                }
            }
            ans.push_back(in);
            ans.push_back(pre);
            ans.push_back(post);
            return ans;
		}
};