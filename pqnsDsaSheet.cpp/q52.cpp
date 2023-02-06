#include<bits/stdc++.h>
using namespace std;


 struct Node{
    int data;
    Node* left;
    Node* right;
 };

 Node* createNewNode(int data){
        Node* curr = new Node;
        curr->data= data;
        curr->left=curr->right= NULL;
        return curr;
 }

 int toFindSum(Node* root, int &ans){
    if(root== NULL)return 0;

    int currS = root->data+ toFindSum(root->left,ans)+toFindSum(root->right, ans);
    
    ans = max(ans, currS);

    return currS;

 }
 int findLargestSubtreeSum(Node* root)
{

    if (root == NULL)    
        return 0;
     
    // Variable to store maximum subtree sum.
    int ans = INT_MIN;
 
    // Call to recursive function to
    // find maximum subtree sum.
  toFindSum(root, ans);
 
    return ans;
}
int main(){

     Node* root = createNewNode(1);
    root->left = createNewNode(-2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(-6);
    root->right->right = createNewNode(2);

    cout<<findLargestSubtreeSum(root);
    return 0;
}