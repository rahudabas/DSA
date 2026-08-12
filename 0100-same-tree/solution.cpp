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
    void rec(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            ans.push_back(INT_MIN);
            return;
            }
        rec(root->left,ans);
        rec(root->right,ans);
        ans.push_back(root->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans1;
        vector<int> ans2;
        rec(p,ans1);
        rec(q,ans2);
        int n=ans1.size();
        int m=ans2.size();
        if(n!=m)return false;
        for(int i=0;i<n;i++){
            if(ans1[i]!=ans2[i])return false;
        }
        return true;
    }
};
