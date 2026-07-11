class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it:nums){
            st.insert(it);
        }
        int maxi=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){ // agr uska chota consecutive nhi h
                int curr=it;
                int cnt=1;
                while(st.find(curr+1)!=st.end()){
                        cnt++;
                        curr++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};
