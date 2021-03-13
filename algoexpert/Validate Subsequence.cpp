using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	int seq_index = 0;
	for(int i=0; i<array.size(); i++){
		if(seq_index >= sequence.size()) break;
		if(array[i] == sequence[seq_index]) seq_index++;
	}
  return seq_index == sequence.size();
}
