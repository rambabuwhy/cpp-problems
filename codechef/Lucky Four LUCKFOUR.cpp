/*
Input
The first line of input consists of a single integer T, denoting the number of integers in Kostya's list.

Then, there are T lines, each of them contain a single integer from the list.

Output
Output T lines. Each of these lines should contain the number of occurences of the digit 4 in the respective integer from Kostya's list


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
        int coun=0;
        char s[1000000];
        cin>>s;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i] == '4')
                coun++;
        }
        cout<<coun<<endl;
    }
}
