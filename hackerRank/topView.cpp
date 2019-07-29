#include<bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
      data = d;
      left = NULL;
      right = NULL;
    }
};

class Solution {
  public:
    Node* insert(Node* root, int data) {
      if(root == NULL) {
        return new Node(data);
      } else {
        Node* cur;
        if(data <= root->data) {
          cur = insert(root->left, data);
          root->left = cur;
        } else {
          cur = insert(root->right, data);
          root->right = cur;
        }

        return root;
      }
    }

    void topView(Node * root) {

      if(!root) return;
      queue< Node * > q;
      int hd = 0;
      std::map<int,int> map;
      std::map<int,int> rmap;

      q.push(root);
      rmap[root->data]= hd;

      while(!q.empty()){

        Node *cNode = q.front();

        q.pop();
        int chd = rmap[cNode->data];

        if(!map.count(chd)){
          map[chd]= cNode->data;
        }

        if(cNode->left){
          int l= rmap[cNode->data];
          rmap[cNode->left->data]= --l;
          q.push(cNode->left);
        }

        if(cNode->right){
          int r= rmap[cNode->data];
          rmap[cNode->right->data]= ++r;
          q.push(cNode->right);
      
        }
      }
      for(auto itr : map)
        cout<<itr.second<<" ";

    }

}; //End of Solution

int main() {

  Solution myTree;
  Node* root = NULL;

  int t;
  int data;

  std::cin >> t;

  while(t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.topView(root);
  return 0;
}

