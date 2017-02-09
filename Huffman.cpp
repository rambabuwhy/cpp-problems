// C++ program for Huffman Coding
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


struct MinHeapNode
{
	long data;
	long freq;
	MinHeapNode *left, *right;

	MinHeapNode(long data, long freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};


void printCodes(struct MinHeapNode* root, string str)
{
    static int max = 0;
    static int min = 100000;
	if (!root)
		return;

	if (root->data != '$')
    {
        cout << root->data << ": " << str << " ("<<str.length()<<") "<<"\n";
        if(max < str.length())
        {
            max = str.length();
        }
        if(min > str.length())
        {

            min = str.length();
        }
    }


	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");

	cout<<" MAX: "<<max <<endl;

	cout<<" MIN: "<<min <<endl;
}

void HuffmanCodes(vector<long> data, vector<long> freq, int size)
{
	struct MinHeapNode *left, *right, *top;


	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));


	while (minHeap.size() != 1)
	{

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();


		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}


	printCodes(minHeap.top(), "");
}

int main()
{
    std::ifstream file1("D://huffman.txt");
    std::string str1;
    getline(file1, str1);
    unsigned int total=atoi (str1.c_str());
    vector<long> arr;
    vector<long> freq;
    cout<<"Number of weights: "<<total<<endl;
    cout<<" size of int: "<<sizeof(int)<<endl;
    for (int i =0;i<total;i++){
        str1="";
        getline(file1, str1);
        long e=atoi (str1.c_str());
        //cout<< " --> : "<<e<<endl;
        //usleep(200000);
        arr.push_back(e);
        freq.push_back(e);

    }

    cout<<" vector total elements: "<<arr.size()<<endl;



	HuffmanCodes(arr, freq, total);

	return 0;
}


