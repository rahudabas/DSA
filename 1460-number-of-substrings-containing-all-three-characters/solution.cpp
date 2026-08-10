class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1;
        int l=0,r=0;
        int n=s.length();
        int cnt=0;
        while(r<n){
            if(s[r]=='a'){
                a=r;
            }
            else if(s[r]=='b')b=r;
            else c=r;
            if(a!=-1 && b!=-1 && c!=-1){
                // cnt+=(n-max(a,max(b,c)));
                cnt+=1+(min(a,min(b,c)));
            }
            r++;
        }
        return cnt;
    }
};
