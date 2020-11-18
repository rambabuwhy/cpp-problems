/*

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()<=1) return intervals;
        
        
        //sort based on start time
        sort(   intervals.begin(), 
                intervals.end(),
                [](const vector<int> &a,const vector<int> &b){
                    return a[0] < b[0];
                    
                });
        
        //insert first interval and compare from second
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for(int i = 1;i<intervals.size();i++){
            //merge: insert max of end time of both
            if(result.back()[1]>=intervals[i][0]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            
            }
            //no merge : insert
            else{
                result.push_back(intervals[i]);
            }
            
        }
        
        return result;
        
    }
};
