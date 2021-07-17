/*

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

*/

class MedianFinder {
public:
    
    //max heap: smaller half of the numbers
    priority_queue<int> max_pq;
    //min heap: larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> min_pq;
   
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    //size(minheap) = size(maxheap) + 1
    void addNum(int num) {
        
        //always move big number to min heap
        //todo that first push into max  then move top to min heap
        max_pq.push(num);
        min_pq.push(max_pq.top());
        max_pq.pop();

        //re balance
        if (max_pq.size() < min_pq.size()) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        } 
    }
    
    double findMedian() {
        
         if ( max_pq.size() > min_pq.size()){
             return max_pq.top();
         } else {
             return ((double) max_pq.top() + min_pq.top()) * 0.5;
         }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
