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
    int rec(TreeNode* root,int& maxi){
        if(root==NULL){
            return 0;
        }
        int lh=max(0,rec(root->left,maxi))+root->val;
        int rh=max(0,rec(root->right,maxi))+root->val;
        maxi=max(maxi,lh+rh-root->val);
        return max(lh,rh);
    }

    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        rec(root,maxi);
        return maxi;
    }
};
