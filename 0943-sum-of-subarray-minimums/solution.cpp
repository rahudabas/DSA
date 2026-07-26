class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int total=0, mod=(int)1e9+7;
        vector<int> nse(n);

        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]= st.empty() ? n : st.top();
            st.push(i);
        }

        stack<int> st2;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()]>arr[i]){
                st2.pop();
            }
            pse[i]= st2.empty() ? -1: st2.top();
            st2.push(i);
        }

        for(int i=0;i<n;i++){
            int left= i- pse[i];
            int right= nse[i]-i;

            total=( total+ (right*left*1LL*arr[i])%mod)%mod;
        }
    return total;
    }
};
