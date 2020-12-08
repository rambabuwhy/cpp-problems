/*

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<int> R(60);
        
        int count = 0;
        
        for(int i =0;i< time.size(); i++){
            
            if(time[i] % 60 == 0)
            count = count + R[0];
            
            else
            count = count + R[60 - time[i] % 60];
            
            
            R[time[i]%60]++;
            
        }
        
        return count;
        
    }
};
