class Solution {
public:
    void rec(vector<string>& ans,string res,int ind,string& digit,string mpp[]){
        if(ind>=digit.length()){
            ans.push_back(res);
            return;
        }
        int num=digit[ind]-'0';
        string val=mpp[num];

        for(int i=0;i<val.length();i++){
            res.push_back(val[i]);
            rec(ans,res,ind+1,digit,mpp);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string res;
        vector<string> ans;
        string mpp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        rec(ans,res,0,digits,mpp);
        return ans;
    }
};
