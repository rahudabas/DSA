class Solution {
public:
    int helper(const string& s,int i,long long nums, int sign){
        //base case
        if(i>=s.size() || !isdigit(s[i])){
            return int(nums*sign);
        }

        nums=nums*10+(s[i]-'0');

        if(nums*sign <=INT_MIN)return INT_MIN;
        if(nums*sign >=INT_MAX)return INT_MAX;

        return helper(s,i+1,nums,sign);
    }
    
    int myAtoi(string s) {
        int i=0;
        //for to skip whitespace
        while(i<s.size() && s[i]==' ' )i++;

        //for doingsign checking 
        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        long long num=0;
        //helper function
        return helper(s,i,num,sign);
    }
};
