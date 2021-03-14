#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
	vector<int> result(array.size());
	
	int left = 0;
	int right = array.size()-1;

	for(int i=array.size()-1; i>=0; i--){
		if(abs(array[left]) > abs(array[right])){
			result[i]= array[left] * array[left];
			left++;
			
		}
		else {
			result[i]=array[right] * array[right];
			right--;
			
		}
		
	}
	
  return result;
}
