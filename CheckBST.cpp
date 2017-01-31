int data[10000];
int cnt=0;
void inorder(Node *root){
    if(root == NULL)
        {
        return;
    }
    inorder(root->left);
    data[cnt++]=root->data;
    inorder(root->right);
    
    
}
   bool checkBST(Node* root) {
       
       if(root == NULL){
           return true;
       }
       
       inorder(root);
       
       for(int i =1;i<cnt;i++){
           if(data[i] <= data [i-1])
               return false;
       }
return true;
   }