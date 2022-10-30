#include<bits/stdc++.h>
using namespace std;




void dfs(vector<vector<int>> &g,vector<int> &v, int node){
    v[node]=1;

    for(int i=0;i<g[node].size();i++){
        int child=g[node][i];
        if (v[child] == 0){
            dfs(g,v,child);
        }
    }

}

int main(){


    int cc=0;  //number of connected components
    int n,m;  //number of nodes and edges

    cout<<"number of nodes & edges:";
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> v(n+1);

    cout<<"Enter edge details:"<<endl;
    for(int i=0;i<m;i++){
        int a,b; //edge nodes
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        if(v[i]==0){
            dfs(g,v,i);
            cc++;
        }
    }

    cout<<"Number of Connected components:  "<<cc<<endl;

    return 0;
}
