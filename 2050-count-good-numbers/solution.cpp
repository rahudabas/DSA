class Solution {
public:
    const long long mod=1e9+7;

    long long pow(long long a,long long b){
        if(b==0)return 1;

        long long half=pow(a,b/2);

        long long result=half*half % mod;
        if(b%2==1){
            result=result*a %mod;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long x=5;
        long long y=4;
        return pow(x,(n+1)/2)*pow(y,n/2) % mod;
    }
};
