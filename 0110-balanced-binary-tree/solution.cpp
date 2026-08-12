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
    int rec(TreeNode* root,int cnt,int& check){
        if(root==NULL){
            return cnt;
        }
        int l=rec(root->left,cnt+1,check);
        int r=rec(root->right,cnt+1,check);

        if((l==r || l-r==1 || l-r==-1) && check!=-1)return max(l,r);
        else return check=-1;
    }
    bool isBalanced(TreeNode* root) {
        int check=0;
        int ans=rec(root,0,check);
        if(check==-1)return false;
        return true;
    }
};
