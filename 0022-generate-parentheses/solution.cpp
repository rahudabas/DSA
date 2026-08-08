class Solution {
public:
    void rec(vector<string>& ans,string res,int n1,int n2,int n){
        if(n1==n){
            if(n2==n){
                ans.push_back(res);
                return;
            }
            else rec(ans,res+')',n1,n2+1,n);
        }
        else{
            if(n2>n1){
                return;
            }
            else if(n1>n2){
                rec(ans,res+'(',n1+1,n2,n);
                rec(ans,res+')',n1,n2+1,n);
            }
            else rec(ans,res+'(',n1+1,n2,n);
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        string res;
        vector<string> ans;
        rec(ans,res,0,0,n);
        return ans;
    }
};
