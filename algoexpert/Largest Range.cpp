#include <vector>
using namespace std;

/*

  Write a function that takes in an array of integers and returns an array of
  length 2 representing the largest range of integers contained in that array.
  
  The first number in the output array should be the first number in the range,
  while the second number should be the last number in the range.
  
  Input :  = [1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6]
  OutPut: [0,7]

*/
vector<int> largestRange(vector<int> array) {
  // Write your code here.
	
	unordered_set<int> lset(array.begin(), array.end());
	vector<int> result;
	int total_diff = 0;
	for(int i=0; i<array.size(); i++){
		int curr_diff = 1;
		
		//left
		int left = array[i]-1;
		while(lset.find(left) != lset.end()){
			lset.erase(left);
			curr_diff++;
			left--;
			
		}
		//right
		int right = array[i]+1;
		while(lset.find(right) != lset.end()){
			lset.erase(right);
			curr_diff++;
			right++;
			
		}
		
		if(total_diff < curr_diff){
			total_diff = curr_diff;
			result = {left+1, right-1}; //include curr element +1 for left and -1  for right
		}
		
	}
  return result;
}
