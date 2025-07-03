class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ds;
        int i = 0;
        int j = numbers.size() - 1;
        while(numbers[i] + numbers[j] != target){
            if(numbers[i] + numbers[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        i++;j++;
        ds.push_back(i);
        ds.push_back(j);
        return ds;
    }
};
