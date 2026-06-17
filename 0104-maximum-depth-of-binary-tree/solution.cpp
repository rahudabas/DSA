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
    void inord(TreeNode* root,int& maxcnt,int cnt){
        if(root==NULL){
            maxcnt=max(maxcnt,cnt);
            return;
        }
        inord(root->left,maxcnt,cnt+1);
        inord(root->right,maxcnt,cnt+1);
    }
    int maxDepth(TreeNode* root) {
        int maxcnt=0;
        int cnt=0;
        inord(root,maxcnt,cnt);
        return maxcnt;
    }
};
