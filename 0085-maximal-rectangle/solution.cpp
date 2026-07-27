class Solution {
public:
    int lefi(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i] ){ //mtlb nse mil gya for top elem
                int element=st.top();
                st.pop();
                int nse=i;
                int pse= st.empty()?-1:st.top();

                maxi=max(maxi, heights[element]* (nse-pse-1));                
           }
           st.push(i);
        }

        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi, heights[element]*(nse-pse-1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>> psum(n,vector<int>(m));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]-'0'==0)sum=0;
                psum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,lefi(psum[i]));
        }
        return maxi;
    }
};
