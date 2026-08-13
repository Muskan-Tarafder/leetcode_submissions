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
    void solve(TreeNode* root,int targetSum,int curSum,vector<vector<int>> &ans, vector<int> &temp){
        if(root==NULL ){
            return;
        }
        if(targetSum==curSum+(root->val)){
            if(root->left==NULL && root->right==NULL){
                // cout<<"last added value: "<<root->val<<endl;
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
            // else{
            //     return;
            // }
        }
       
            // cout<<"trying to add: "<<root->val<<"target value: "<<targetSum<<endl;
        temp.push_back(root->val);
        solve(root->left,targetSum,curSum+(root->val),ans,temp);
        solve(root->right,targetSum,curSum+(root->val),ans,temp);
        temp.pop_back();

        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,targetSum,0,ans,temp);
        return ans;
    }
};