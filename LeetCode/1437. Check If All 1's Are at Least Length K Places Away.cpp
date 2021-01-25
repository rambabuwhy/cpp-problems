1437. Check If All 1's Are at Least Length K Places Awayclass Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = k;
        
        for (int num : nums) {
            
            if (num == 1) {
                    if (count < k) 
                    return false;    
                
                    count = 0;
          
            } else {
                
                ++count;    
            } 
        }        
        return true;
    }
};
