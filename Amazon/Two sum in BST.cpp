// Given the root of a binary search tree and an integer k.Return true if there exist two elements in the BST such that their sum is equal to k otherwise false.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
class BSTIterator{
    public:
    stack<TreeNode*>s;
    bool reverse;
    void pushAll(TreeNode* node){
        while(node){
            s.push(node);
            node = (reverse) ?node->right : node->left;
        }
    }
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }
    bool hasNext() {
        return !s.empty();
    }
    int next(){
        TreeNode* node = s.top();
        s.pop();
        if(!reverse)pushAll(node->right);
        else pushAll(node->left);
        return node->data;
    }
};
class Solution{	
	public:
		bool twoSumBST(TreeNode* root, int k){
			//your code goes here
            if(!root)return false;
            BSTIterator l(root,false);
            BSTIterator r(root,true);
            int i = l.next();
            int j = r.next();
            while(i<j){
                if(i+j==k)return true;
                else if(i+j<k)i = l.next();
                else j = r.next();
            }
            return false;
		}
};