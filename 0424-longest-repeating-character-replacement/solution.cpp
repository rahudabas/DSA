class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
        int n=s.length();
        int l=0,r=0;
        int maxi=0;
        int maxf=0;
        while(r<n){
            mpp[s[r]-'a']++;
            maxf=max(maxf,mpp[s[r]-'a']);
            if((r-l+1)-maxf>k){
                mpp[s[l]-'a']--;
                // if(mpp[s[l]-'a']==0){
                //     mpp.erase(s[l]-'A');
                // }
                l++;
            }
            else{
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};
