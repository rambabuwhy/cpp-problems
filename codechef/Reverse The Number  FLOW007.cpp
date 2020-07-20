/*
Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
For each test case, display the reverse of the given number N, in a new line.
*/

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
int main()
{
  long long   int tc;
    cin>>tc;
    while(tc--)
    {
        int n=0,result=0,rem=0;
        cin>>n;
        while(n){

            rem = n % 10;
            n = n / 10;
            result = result * 10 + rem;

        }
        cout<<result<<endl;
    }

    return 0;
}
