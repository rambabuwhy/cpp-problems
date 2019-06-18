#include<iostream>
#include<vector>
using namespace std;
bool search2D(vector<vector<int>>& A, int x)
{
  int R=0,C=A[0].size()-1;
  while(R < A.size() && C >= 0)
  {
    if(A[R][C] == x) return true;
    else if(A[R][C] < x) ++R;
    else --C;
  }
  return false;
}
int main()
{
  vector<vector<int>> A = { {3,4,5,6,7},
                            {10,11,12,13,14},
                            {23,24,25,16,17},
                            {43,44,45,46,47}};
  int x;
  cout<<"Search: ";
  cin>>x;
  bool R=search2D(A,x);
  if(R == true) cout<<"Found" <<endl;
  else cout<<"Not Found" <<endl;
  return 0;


}
