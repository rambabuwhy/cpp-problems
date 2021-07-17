/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& input1, vector<int>& input2) {
            
        //make always input 2  big
        if (input1.size() > input2.size()) return findMedianSortedArrays(input2, input1);
        
        int x = input1.size();
        int y = input2.size();

        int low = 0;
        int high = x;
        while (low <= high) {
            
            //Partition X  
            int x_partition = (low + high)/2;
            
            //Partition Y 
            int y_partition = (x + y + 1)/2 - x_partition;
            
            //variables which partition x 
            int maxLeftX = (x_partition == 0) ? INT_MIN : input1[x_partition - 1];
            int minRightX = (x_partition == x) ? INT_MAX : input1[x_partition];
            
            //variables which partition y
            int maxLeftY = (y_partition == 0) ? INT_MIN : input2[y_partition  - 1];
            int minRightY = (y_partition == y) ? INT_MAX : input2[y_partition ];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // right way of partition
                if ((x + y) % 2 == 0) return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                else return (double)max(maxLeftX, maxLeftY);
            } else if (maxLeftX > minRightY) { 
                //move leftside
                high = x_partition - 1;
            } else { 
                //move rightside
                low = x_partition + 1;
            }
        }
        return -1;
    }
};
