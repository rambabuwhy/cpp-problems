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

	int T,I;
	cin>>T;
	while(T--){
	    cin>>I;
	    if(I <= 2) {
	        cout<<I<<endl;
	        continue;
	    }

        vector<int> arr(1000,0);
        int N = 0;
        arr[0]=1;
        N++;

        int carry = 0;
        for(int i = 2;i <= I; i++){

                for(int j = 0; j<N; j++) {
                    int Multi = arr[j] * i + carry;
                    arr[j] = Multi % 10;
                    carry = Multi / 10;

                }

                while(carry){
                    arr[N] = carry % 10;
                    carry = carry / 10;
                    N++;
                }

        }
        for(int i= N-1;i>=0;i--){
            cout<<arr[i];
        }
        cout<<endl;



	}
	return 0;
}
