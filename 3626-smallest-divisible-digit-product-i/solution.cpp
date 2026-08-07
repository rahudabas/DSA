class Solution {
public:
    int smallestNumber(int n, int t) {
        int cnt=false;
        while(n<=100){
            int a=n/100;
            int b=(n%100)/10;
            int c=(n%10);
            if(n<10){
                if(c%t==0)return n;
                else {
                    n++;
                    continue;
                }
            }
            else if(n==100){
                if((a*b*c)%t==0)return n;
                continue;
            }
            else{
                if((b*c)%t==0)return n;
                else{
                    n++;
                    continue;
                } 
            }
        }
        return -1;
    }
};
