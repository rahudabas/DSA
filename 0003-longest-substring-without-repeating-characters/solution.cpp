class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        int n=s.length();
        int l=0,r=0;
        int maxi=0;
        while(r<n){
            if(mpp[s[r]]!=-1){//mtlb wo pehle mil chuka h
                if(mpp[s[r]]>=l){
                    l=mpp[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxi=max(len,maxi);
            mpp[s[r]]=r;
            r++;
        }
        return maxi;
    }
};
