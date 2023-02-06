// bst from preorder

#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int data;
   Node* left;
   Node* right;

   Node(int key){
    this->data= key;
    left=right= NULL;
   }


};
static Node* root;

Node* createN(Node* root, int key){
    if(root== NULL){
        root= new Node(key);
    }
    if(root->data > key){
        root->left= createN(root->left, key);
    }
    if(root->data< key){
        root->right= createN(root->right, key);
    }
    return root;
}
void create(int data) { root = createN(root, data); }

void inorderRec(Node* root)
{
    if (root != NULL) {
        inorderRec(root->left);
        cout << root->data << " ";
        inorderRec(root->right);
    }
}
 

int main()
{
    vector<int> nodeData = { 10, 5, 1, 7, 40, 50 };
 
    for (int i = 0; i < nodeData.size(); i++) {
        create(nodeData[i]);
    }
    inorderRec(root);
}