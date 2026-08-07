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
    int findPos(int ele,int st,int en,vector<int>& inorder){
        for(int i=st;i<=en;i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return st;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &i,int st,int en,int n){
        if(i>=n || st>en){
            return NULL;
        }
        int ele=preorder[i++];
        TreeNode* node=new TreeNode(ele);
        int pos=findPos(ele,st,en,inorder);
        node->left=solve(preorder,inorder,i,st,pos-1,n);
        node->right=solve(preorder,inorder,i,pos+1,en,n);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        TreeNode* root=solve(preorder,inorder,i,0,preorder.size()-1,preorder.size());
        return root;
    }
};