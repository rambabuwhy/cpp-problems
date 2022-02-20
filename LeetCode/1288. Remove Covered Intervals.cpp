/*
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1

*/

class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            
            if(a[0]==b[0]){
                return b[1] < a[1];
            }else{
                return a[0] < b[0];
            }
        });
        
        int prev = 0;
        int count = 0;
        for(auto interval:intervals){
            
            if(prev < interval[1]) {
                count++;
                prev = interval[1];
            }
        }
        return count;
    }
};
