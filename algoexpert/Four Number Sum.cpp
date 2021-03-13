#include <vector>
using namespace std;
void util(vector<int> &array, vector<vector<int>>  &result, int first, int second, int targetSum){
		
		
		int left = second + 1;
		int right = array.size()-1;
		while(left < right) {
			int currSum = array[first] + array[second] + array[left] + array[right];
			if( currSum == targetSum){
				result.push_back({array[first],array[second], array[left], array[right]});
				left++;
				right--;
			}
			
			else if(currSum < targetSum){
				left++;
			}
			else{
				right--;
			}
		}
}


vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	if(array.size() < 4) return vector<vector<int>>();
	vector<vector<int>>  result;
	sort(array.begin(), array.end());
	for(int i=0; i<array.size()-3; i++){
		if(i>0 && array[i] == array[i-1]) continue;
		for(int j=i+1; j<array.size()-2; j++){
			if(j>i+1 && array[j] == array[j-1]) continue;
			util(array,result,i,j,targetSum);
			
		}
	}
		
  return result;
}
	
