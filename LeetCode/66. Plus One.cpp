class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() -1 ; i >= 0; i--){
            if(digits[i] == 9){
                digits[i]=0;
            }
            else{
                digits[i]++;
                return digits;
            }
        }
        
        //reached here: all previous numbers are 9's
        digits.insert(digits.begin(),1);
        return digits;
    }
};
