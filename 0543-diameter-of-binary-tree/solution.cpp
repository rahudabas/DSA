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
    int diam(TreeNode* root,int& maxcnt){
        if(root==NULL){
            return 0;
        }
        int lh=diam(root->left,maxcnt);
        int rh=diam(root->right,maxcnt);

        maxcnt=max(maxcnt,lh+rh);
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int maxcnt=0;
        int cnt=0;
        cnt=diam(root,maxcnt);
        return maxcnt;
    }
};
