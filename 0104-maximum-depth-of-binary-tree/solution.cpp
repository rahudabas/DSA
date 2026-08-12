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
    void rec(TreeNode* root,int cnt,int& maxi){
        if(root==NULL){
            maxi=max(cnt,maxi);    
            return;
        }
        rec(root->left,cnt+1,maxi);
        rec(root->right,cnt+1,maxi);
    }
    int maxDepth(TreeNode* root) {
        int maxi=0;
        rec(root,0,maxi);
        return maxi;
    }
};
