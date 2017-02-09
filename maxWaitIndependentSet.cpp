#include <bits/stdc++.h>
#include <fstream>
#include<iomanip>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <unistd.h>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){

    long a[1001]={0};
    long s[1001]={0};
    std::ifstream file1("D://mwis.txt");
    std::string str1;
    getline(file1, str1);
    unsigned int total=atoi (str1.c_str());

    cout<<"Number of weights: "<<total<<endl;
    cout<<" size of int: "<<sizeof(int)<<endl;
    a[0]=0;
    for (int i =1;i<total+1;i++){
        str1="";
        getline(file1, str1);
        long e=atoi (str1.c_str());
        a[i]=e;
       // cout<<a[i]<<endl;
       if(i==1 || i ==2 || i ==3 || i == 4
          ||i ==17 || i==117 || i==517 || i==997 )
            cout<<a[i]<<endl;


    }
    //exit(0);

    int j=total;

    int k = 0;

cout<<"  CODE HERE  "<<endl;

    s[0] = 0;
    s[1] = a[1];

    for(int i = 2 ; i < total +1 ; ++i){
        s[i] = max( s[i-1] , s[i-2] + a[i] );
    }
    vector<long> result;
    while(j>=1){
            if(s[j-1] < (s[j-2]+a[j]))
            {

                cout << j <<" , "<<endl;
               // s[k]=a[j];
               result.push_back(a[j]);
                j = j-2;

            }
            else{
                    j = j-1;
            }
    }
/*
    for(int l = 0;l<k;l++)
    {

        cout<<l<<" : " <<s[l]<<endl;
    }
  */

  //1, 2, 3, 4, 17, 117, 517, and 997,


    for(int m=0; m<1000;m++)
    {

         if(m==1 || m ==2 || m ==3 || m == 4
          ||m ==17 || m==117 || m==517 || m==997 )
          {


            cout<<a[m]<<" : ";


                vector<long> ::iterator  itr;
                itr=std::find (result.begin(), result.end(), a[m]);
                //vector<long> ::iterator itr= result.find(a[m]);
                if(itr!=result.end())
                {
                    cout<<" 1"<<endl;

                }
                else{

                        cout<<" 0"<<endl;

                }


        }

    }
    cout<<endl;

    return 0;
    }
