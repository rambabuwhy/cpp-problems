#include <iostream> 
#include <stdlib.h>
using namespace std; 
  
void printTwoElements(int arr[], int size) 
{ 
      int i; 
      cout << "The repeating element is "; 
           
      for (i = 0; i < size; i++) 
      { 
           if (arr[abs(arr[i]) -1] > 0) 
                 arr[abs(arr[i]) -1] = -arr[abs(arr[i]) -1]; 
           else
                 cout << abs(arr[i]) << "\n"; 
      } 
      cout<<endl;
      for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
      cout<<endl;
                
      cout << "and the missing element is "; 
      for (i = 0; i < size; i++) 
      { 
           if (arr[i] > 0) 
              cout << (i + 1); 
      } 
      cout<<endl;
} 
  
/* Driver code */
int main() 
{ 
      int arr[] = { 5, 3, 0, 3, 1, 2}; 
      int n = sizeof(arr) / sizeof(arr[0]); 
      printTwoElements(arr, n); 
} 
  
// This code is contributed by Shivi_Aggarwal
