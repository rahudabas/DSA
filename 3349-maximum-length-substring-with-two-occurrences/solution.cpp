class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> arr(26,0);
        unordered_map<int,int> mpp;
        int n=s.length();
        int maxi=0;

        int l=0,r=0;
        while(r<n){
            mpp[s[r]]++;
            if(mpp[s[r]]>2){
                while(mpp[s[r]]>2){
                    mpp[s[l]]--;
                    l++;
                }
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
