/*

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        sort(
            intervals.begin(),
            intervals.end(),
            [](vector<int> &f,vector<int> &s)
                {
                 return f[0]<s[0];
                }
        );
        
        
        for(int i =1;i<intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]){
                return false;
            }
            
        }
        
        
        
        return true;
        
    }
};
