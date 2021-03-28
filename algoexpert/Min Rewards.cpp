#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
  // Write your code here.
	
	vector<int> result(scores.size(),1);
	
	//left to right:  increment if it is increasing order
	for(int i=1; i<scores.size(); i++){
		if(scores[i] > scores[i-1]){
			result[i] = result[i-1] + 1;
		}
	}
	
	//right to left: increment if it is increasing order also take max of left ot right value
	for(int i=scores.size()-2; i>=0; i--){
		if(scores[i] > scores[i+1]){
			result[i] = max(result[i], result[i+1]+1);
		}
	}
  return accumulate(result.begin(), result.end(), 0);
}
