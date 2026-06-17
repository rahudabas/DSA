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
    int inord(TreeNode* root,int&check,int cnt){
        if(root==NULL){
            return cnt;
        }
        int l=inord(root->left,check,cnt+1);
        int r=inord(root->right,check,cnt+1);

        if((l-r==0 ||l-r== 1||l-r==-1) && check!=-1){
            return max(l,r);
        }
        else{
            return check=-1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int cnt=0;
        int check=0;
        if(inord(root,check,cnt)==-1)return false;
        return true;
    }
};
