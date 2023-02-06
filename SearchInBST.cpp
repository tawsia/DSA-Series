
    // Following is the Binary Tree node structure:
  #include<bits/stdc++.h>
  using namespace std;
    class BinaryTreeNode {
    public : 
        int data;
        BinaryTreeNode  *left;
        BinaryTreeNode  *right;

        BinaryTreeNode(int data) {
            this -> data = data;
           this->left =  NULL;
           this->right = NULL;
        }
    };


bool searchInBST(BinaryTreeNode *root, int x) {
    // Write your code here.
// //     base case
//     if(root== NULL){
//         return false;
//     }
//     if(root->data== x){
//         return true;
//     }
//     if(root->data>x){
// //         left part m
//         return searchInBST(root->left, x);
//     }
//     else{
// return searchInBST(root->right, x);
//         }
//     iterative way
    BinaryTreeNode *temp= root;
    while(temp != NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp= temp->left;
        }else{
            temp= temp->right;
        }
    }
    return false;
}