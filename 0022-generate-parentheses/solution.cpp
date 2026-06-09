class Solution {
public:
    void generate(string s,vector<string>& valid,int open, int close){
        if(open==0 && close==0){
            valid.push_back(s);
            return;
        }

        if(open>0){
            s.push_back('(');
            generate(s,valid,open-1,close);
            s.pop_back();
        }
        if(close>0){
            if(open<close){
                s.push_back(')');
                generate(s,valid,open,close-1);
                s.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> valid;
        int open=n,close=n;
        string s="";
        generate(s,valid,open,close);
        return valid;
    }
};
