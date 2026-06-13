class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int nofive=0;
        int noten=0;
        int notwen=0;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                nofive++;
            }
            else if(bills[i]==10){
                if(nofive!=0){
                    noten++;
                    nofive--;
                }
                else return false;
            }
            else{
                if(nofive!=0 && noten!=0){
                    noten--;
                    nofive--;
                    notwen++;
                }
                else if(nofive>=3){
                    nofive=nofive-3;
                    notwen++;
                }
                else return false;
            }
        }
    return true;
    }
};
