#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;



  Node(int d){
    this->data= d;
    this->left= NULL;
    this->right= NULL;
  }
};
void leveOrderTraversal(Node* root){
   queue<Node*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty()){
    Node* temp= q.front();
    q.pop();

    if(temp==NULL){
        // purana level complete ho chuka h
        cout<<endl;
        if(!q.empty()){
            // q still have some child node
            q.push(NULL);
        }
    }
    else{
    cout<<temp->data<<" ";
    if(temp->left)
     q.push(temp->left);
   
    if(temp->right)
     q.push(temp->right);
    }
   
}
}
void inOrder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(Node* root){
    // base case
    if(root == NULL)
    return;


      cout<<root->data<<" ";
       preOrder(root->left);
        preOrder(root->right);
}
void postOrder(Node* root){
    // base case
    if(root == NULL)
    return;


       postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
}
Node* insertIntoBst(Node* root, int d){
    // base case
    if(root==NULL){
        root= new Node(d);
        return root;
    }
    if(d>root->data){
        // right part m insert karo
        root->right= insertIntoBst(root->right, d);
    }
    else if(d<root->data){
        // left m insert karo
        root->left= insertIntoBst(root->left, d);
    }
    return root;
}
Node* minVal(Node* root){
    Node* temp= root;
    while(temp->left != NULL){
       temp= temp->left;

    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp= root;
    while(temp->right != NULL){
       temp= temp->right;

    }
    return temp;
}
Node* nodeToDelete(Node* root, int x){
        //  base case
        if(root== NULL){
            return root;
        }
        if(root->data== x){
            // 0 child
             if(root->left && root->right== NULL){
                delete root;
                return NULL;
             }
            // 1 child
           //left child
           if(root->left != NULL && root->right== NULL){
            Node* temp= root->left;
            delete root;
            return temp;
           }
        //    right child
           if(root->left == NULL && root->right != NULL){
            Node* temp= root->right;
            delete root;
            return temp;
           }

            // 2 child
            if(root->left != NULL && root->right != NULL){
                int mini= minVal(root->right)->data;
                root->data= mini;
                 root->right= nodeToDelete(root->right, mini);
                 return root;
            }
        }
        else if(root->data>x){
            root->left= nodeToDelete(root->left, x);
            return root;
        }
        else{
            root->right= nodeToDelete(root->right,x);
            return root;
        }
}
void takeInput(Node* &root){
  int data;
  cin>>data;

  while(data != -1){
    insertIntoBst(root,data);
    cin>>data;
  }
}

int main(){

  Node* root= NULL;
  cout<<"Enter data to create BST"<<endl;
  takeInput(root);

 cout<<"Printing the BST"<<endl;
 inOrder(root);

 cout<<"Printing the BST"<<endl;
 preOrder(root);

 cout<<"Printing the BST"<<endl;
 postOrder(root);

 cout<<"Printing the BST"<<endl;
 leveOrderTraversal(root);
cout<<"Min value is "<<minVal(root)->data<<endl;
cout<<"Max value is "<<maxVal(root)->data<<endl;

root= nodeToDelete(root,30);

cout<<"Printing the BST"<<endl;
 inOrder(root);

 cout<<"Printing the BST"<<endl;
 preOrder(root);

 cout<<"Printing the BST"<<endl;
 postOrder(root);

 cout<<"Printing the BST"<<endl;
 leveOrderTraversal(root);
cout<<"Min value is "<<minVal(root)->data<<endl;
cout<<"Max value is "<<maxVal(root)->data<<endl;

    return 0;
}
// inorder prdecessor and successor home workcf