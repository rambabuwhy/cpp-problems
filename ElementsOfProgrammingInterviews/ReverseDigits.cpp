#include <iostream>
using namespace std;

int reverseDigits(int d){
  int result=0;
  while(d){
    int p=d%10;
    cout<<"Percentage:"<<p<<endl;
    result = result * 10 + p;
    d = d/10;
    cout<<"Divides:"<<d<<endl;
  }
  return result;

}
int main()
{
  cout<<"12:"<<reverseDigits(12)<<endl;
  cout<<"52:"<<reverseDigits(52)<<endl;



  return 0;
}
