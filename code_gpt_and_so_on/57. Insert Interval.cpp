/*

Author: Rambabu Yerajana
linkedin: https://www.linkedin.com/in/rambabuyerajana/
problem: Insert Interval
------------------------------------------------------------------
Problem:
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
------------------------------------------------
Solution:
The solution first stores the start and end values of the newInterval in variables start and end, respectively. The result is stored in a vector result.

In the first while loop, the solution adds all intervals that have an end value that is less than the start value of the newInterval to the result vector.

In the second while loop, the solution merges overlapping intervals by updating the start and end values and adding them to the result vector.
The loop continues until all overlapping intervals have been merged or there are no more intervals to consider.

In the third while loop, the solution adds the remaining intervals (if any) to the result vector.

Finally, the function returns the result vector, which contains the intervals after inserting the newInterval.
------------------------------------------------
Yes, this is an optimized solution as it has a time complexity of O(n), where n is the number of intervals in the given array. 
The solution performs a linear scan of the intervals array, and uses a constant amount of space to store the result. Additionally, 
the use of two while loops helps to avoid unnecessary operations and further optimizes the solution.
*/



#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int start = newInterval[0];  // store the start of newInterval
    int end = newInterval[1];    // store the end of newInterval
    vector<vector<int>> result; // vector to store the result

    int i = 0;
    // add intervals with end less than start of newInterval
    while (i < intervals.size() && intervals[i][1] < start) {
        result.push_back(intervals[i]);
        i++;
    }

    // merge overlapping intervals
    while (i < intervals.size() && intervals[i][0] <= end) {
        start = min(start, intervals[i][0]); // update start
        end = max(end, intervals[i][1]);     // update end
        i++;
    }
    result.push_back({start, end}); // add the merged interval

    // add remaining intervals
    while (i < intervals.size()) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}
