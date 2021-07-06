/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1

*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
    
        sort(intervals.begin(), intervals.end(), [](vector<int> &x, vector<int> &y){return x[0] < y[0];});

        for(int i=0; i<intervals.size(); i++){
            
            if(!pq.empty() && pq.top() <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};

