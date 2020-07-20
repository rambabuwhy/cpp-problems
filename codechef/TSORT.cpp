#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cassert>
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define pb push_back
#define mp make_pair
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pin(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define F first
#define S second

using namespace std;

int main() {
	// your code goes here
	int N,I;
	cin>>N;
	vector<long> arr;
	for(int i = 0 ; i<N; i++){
	    cin>>I;
	    arr.push_back(I);
	  
	}
	sort(arr.begin(),arr.end());
	for(int i =0; i< arr.size();i++){
	    cout<<arr[i]<<endl;
	}
	
	return 0;
}
