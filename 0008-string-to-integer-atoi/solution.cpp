class Solution {
public:
    long long rec(string& s,int i,long long num,int sign){
        if(i>=s.size() || !isdigit(s[i]) )return int(sign*num);

        num=num*10 + (s[i]-'0');
        if(num*sign <=INT_MIN)return INT_MIN;
        if(num*sign >=INT_MAX)return INT_MAX;

        return rec(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ')i++;
        int sign=1;
        if(i<s.size() &&(s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='-')?-1 :1;
            i++;
        }
        long long num=0;
        return rec(s,i,num,sign);
    }
};
