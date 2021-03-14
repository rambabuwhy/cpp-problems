#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
	
	if(arrayOne.size() == 0 || arrayTwo.size() == 0){
		return vector<int>();
	}
	
	vector<int> result;
	int index_one = 0;
	int index_two = 0;
	
	int curr_diff = INT_MAX;
	int diff = INT_MAX;
	
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	while(index_one < arrayOne.size() && index_two < arrayTwo.size()){
		int first = arrayOne[index_one];
		int second = arrayTwo[index_two];
		
		if(first < second){
			curr_diff = second - first;
			index_one++;
		}
		else if(first > second){
			curr_diff = first - second;
			index_two++;
		}
		else{  //if diff is 0 then this is answer
			return vector<int>({first,second});
		}
		
		//find diff of all pairs and save if it is minimum
		if(diff > curr_diff){
			diff = curr_diff;
			result = {first,second};	
		}
		
	}
  return result;
}
