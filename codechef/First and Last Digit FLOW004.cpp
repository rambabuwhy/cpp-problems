/*

If Give an integer N . Write a program to obtain the sum of the first and last digits of this number

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

	int t;
	long long i;
	cin>>t;

	while(t--) {
	    cin>>i;
	     int no_d = log10(i);

	     int first = i / (pow(10,no_d));
	     int last = i % 10;

	     cout<< ( first + last)<<endl;

	}
	return 0;
}
