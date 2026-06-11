class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0,maxlen=0;

        int HashLen = 256; 

        int hash[HashLen]; 

        for (int i = 0; i < HashLen; i++) {
            hash[i] = -1;
        }

        while(r<n){
            if(hash[s[r]] != -1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }
    return maxlen;
    }
};
