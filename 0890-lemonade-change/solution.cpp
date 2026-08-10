class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int a=0;
        int b=0;
        int i=0;
        while(i<n){
            if(bills[i]==5)a++;
            else if(bills[i]==10){
                if(a>=1){
                    a--;
                    b++;
                }
                else return false;
            }
            else{
                if(a>=1 && b>=1){
                    a--;
                    b--;
                }
                else if(a>=3){
                    a-=3;
                }
                else return false;
            }
            i++;
        }
        return true;
    }
};
