class Solution {
public:
    const int mod = 1e9 + 7;


    long long power(long long x,long long y){
        long long res=1;

        x=x%mod;

        while(y>0){
            if(y%2==1){
                res=(res*x) %mod;
            }
            x= (x*x) %mod;
            y=y/2;
        }
        return res;
    }    

    int countGoodNumbers(long long n) {
        long long a;
        long long even_index=(n+1)/2 ;
        long long odd_index=n/2;

        long long evenPart = power(5, even_index);
        long long oddPart = power(4, odd_index);

        return (evenPart* oddPart) %mod;
        
        }
};
