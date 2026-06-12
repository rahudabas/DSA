class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxlen=0, maxf=0;
        vector<int> hash(26,0);

        while(r<s.size()){
            hash[s[r]-'A']++; //updates the hash
            maxf=max(maxf,hash[s[r]-'A']);
            int len=r-l+1;
            if(len-maxf>k){ //allowed s jyada changes h
                hash[s[l]-'A']--; //left most ko htayege hash s and window ko agge shift krege
                l=l+1;
            }
            if(r-l+1 -maxf<=k){
                maxlen=max(r-l+1,maxlen);
            }
            r++;
        }
    return maxlen;
    }
};
