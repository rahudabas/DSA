class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int i=0,j=0;

        while(i<s.size() && j<g.size()){
            if(g[j]<=s[i]){
                i++;
                j++;
                cnt++;
            }
            else i++;
        }
    return cnt;
    }
};
