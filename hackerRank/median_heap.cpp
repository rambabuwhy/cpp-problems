#include<iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
class minHeap{
    public:
    int H[5000];
    int size;
    minHeap(){
        size = 0;

    }
    void insert(int d){
        if( size == 5000){
            cout<<"ERROR"<<endl;
            return;
        }
        size = size + 1;
        H[size]= d;
        shiftUP(size);
    }
    int remove(){
        return extractMin();
    }
    int peek(){
        if(size < 1) return 0;
        return H[1];
    }
    int extractMin(){
        int result = H[1];
        H[1]=H[size];
        shiftDOWN(1);
        size = size - 1;
        return result;

    }
    void shiftUP(int i){
        while((i>1) && (H[parent(i)]>H[i])){
            int temp = H[parent(i)];
            H[parent(i)] = H[i];
            H[i]= temp;
            i = parent(i);
        }

    }
    void shiftDOWN(int i){
        //cout<<"......................shiftdown.........................."
        int maxIndex = i;
        int l = lChild(i);
        //cout<<" Left Child: "<<H[l]<<endl;
        if((l <= size) && (H[l]<H[maxIndex])){
            maxIndex = l;
        }
        int r = rChild(i);
        //cout<<" Right Child: "<<H[r]<<endl;
        if((r <= size) && (H[r]<H[maxIndex])){
            maxIndex = r;
        }
        //cout<<" Max Child: "<<H[maxIndex]<<endl;
        if( i != maxIndex){
            int temp = H[i];
            H[i] = H[maxIndex];
            H[maxIndex]= temp;
            shiftDOWN(maxIndex);
        }
        //cout<<"........................................................."

    }
    int parent(int d){
        return floor(d/2);
    }
    int lChild(int d){
        return (2 * d );
    }
    int rChild(int d){
        return (2 * d )+1;
    }
    void disply(){
        for (int i = 1 ; i <= size ; i++)
            cout<<H[i]<<" ";
        cout<<endl;
    }

};
class maxHeap{

    public:
    int H[5000];
    int size;
    maxHeap(){
        size = 0;

    }
    int peek(){
        if(size < 1) return 0;
        return H[1];
    }
    void insert(int d){
        //disply();
        if( size == 5000){
            cout<<"ERROR"<<endl;
            return;
        }
        size = size + 1;
        H[size]= d;
        //cout<<" shift UP: "<<H[size]<<endl;;
        shiftUP(size);
    }
    int remove(){
        return extractMax();
    }
    int extractMax(){
        //cout<<" Remove:  "<<H[1]<<endl;
        //cout<<" Before Remove: ";
        //disply();
        int result = H[1];
        H[1]=H[size];
        size = size - 1;
        //cout<<" After Remove: ";
        //disply();
        shiftDOWN(1);
        //cout<<" After ShiftDown: ";
        //disply();
        return result;

    }
    void shiftUP(int i){
        //cout<<" i: "<<i<<" parent: "<<H[parent(i)]<<" child: "<<H[i]<<endl;
        while((i>1) && (H[parent(i)]<H[i])){
            //cout<<" swapping "<<endl;
            int temp = H[parent(i)];
            H[parent(i)] = H[i];
            H[i]= temp;
            i = parent(i);
            //return;
        }


    }
    void shiftDOWN(int i){
        int maxIndex = i;
        int l = lChild(i);
        if((l <= size) && (H[l]>H[maxIndex])){
            maxIndex = l;
        }
        int r = rChild(i);
        if((r <= size) && (H[r]>H[maxIndex])){
            maxIndex = r;
        }
        if( i != maxIndex){
            int temp = H[i];
            H[i] = H[maxIndex];
            H[maxIndex]= temp;
            shiftDOWN(maxIndex);
        }

    }
    int parent(int d){
        return floor(d/2);
    }
    int lChild(int d){
        return (2 * d );
    }
    int rChild(int d){
        return (2 * d )+1;
    }
    void disply(){
        for (int i = 1 ; i <= size ; i++)
            cout<<H[i]<<" ";
        cout<<endl;
    }

};
void addNumber(int random,maxHeap *maxheap,minHeap *minheap){
    if(maxheap->size == minheap->size){
            if(minheap->peek() && random > minheap->peek()) {
                maxheap->insert(minheap->remove());
                minheap->insert(random);
            }
            else{
                maxheap->insert(random);
            }
    }
    else{
        if(random < maxheap->peek()){
            minheap->insert(maxheap->remove());
            maxheap->insert(random);
        }
        else{
            minheap->insert(random);
        }
    }
//cout<<"..........MIN HEAP ..............."<<endl;
    //minheap->disply();
//cout<<endl;
//cout<<"..........MAX HEAP ..............."<<endl;
    //maxheap->disply();
//cout<<"==============================================="<<endl;
//cout<<endl;



}
double getMedian(maxHeap *maxheap, minHeap *minheap){
   
    double result = 0.0;
    if(maxheap->size <= 0 ) return 0;
    if(maxheap->size == minheap->size){
        //cout << " two points  add: ";
        //cout <<minheap->peek() <<"+"<< maxheap->peek()<<endl;
        result = (double)(minheap->peek() + maxheap->peek())/ 2.0;

    }
    else{
        //cout << " single mid point: "<<maxheap->peek()<<endl;
        result = maxheap->peek();
    }
    return result;
}

int main(){
    maxHeap *maxheap=new maxHeap;
    minHeap *minheap=new minHeap;
    std::ifstream file1("input.txt");
    std::ifstream file2("output.txt");
    std::string str1; 
    getline(file1, str1);
    
    int n=atoi (str1.c_str());
   //int n;
   //cin>>n;
    for(int a_i = 0;a_i < n;a_i++){
        getline(file1, str1);
        int a= atoi (str1.c_str());
        //int a;
        //cin>>a;
        //cout<<"==============================================="<<endl;
        //cout<<" \nNext Number: " << a<<endl;
        addNumber(a,maxheap,minheap);
        std::string str2; 
        getline(file2, str2);
        double o= atof (str2.c_str());
        double r=getMedian(maxheap,minheap);
        cout<<fixed<<std::setprecision(1)<<r<<" : "<<o<<endl;;
        int c;
        br:
       cout<<":";
        cin>>c;
        if(c=1){
            continue;
        }
        else
        {
            goto br;
        }
        //minheap->insert(a[a_i]);

    }
    return 0;
}

