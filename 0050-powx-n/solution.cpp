class Solution {
public:
    double pow(double x,long long i){
        if(i==0)return 1;
        double half=pow(x,i/2);
        if(i%2==0)return half*half;
        else return half*half*x;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            N=-N;
            x=1/x;
        }
        double ans=1.0;
        return pow(x,N);
    }
};
