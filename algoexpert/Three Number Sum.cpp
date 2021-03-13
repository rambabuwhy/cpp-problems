#include <vector>
using namespace std;

void util(vector<int> &array, vector<vector<int>> &result, int targetSum, int index ){
		
	int left = index+1;
	int right = array.size()-1;
	while ( left < right) {
			int currSum = array[left] + array[right] + array[index];
		
			if( targetSum == currSum) {
				result.push_back({array[index], array[left], array[right] });
				left++;
				right--;
				
			}
			else if(currSum > targetSum){
				right--;
			}
			else {
				left++;
			}
			
		}
		
}
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	if(array.size() < 3) return vector<vector<int>>();
	sort(array.begin(), array.end());
	
	vector<vector<int>> result;
	for(int i =0; i<array.size(); i++){
		util(array, result, targetSum, i);
	}
	return result;
}

	
	
