//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
    // int findPosition(int in[], int ele, int n){
    //     for(int i=0; i<n; i++){
    //         if(in[i]==ele){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    void createMapping(int in[], map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]]= i;
        }
    }
    Node* solve(int in[], int post[], int &indexPostOrder, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex){
        // base case
        if(indexPostOrder < 0  || inOrderStart > inOrderEnd){
            return NULL;
        }
        // create a root node for element
        int ele=  post[indexPostOrder--];
        Node* root = new Node(ele);
        
        // find element's index in inorder
        int pos= nodeToIndex[ele];
        // int pos= findPosition(in, ele,n);
        
        // recursive calls
        
        root->right= solve(in,post, indexPostOrder, pos+1, inOrderEnd, n, nodeToIndex);
        root->left= solve(in,post,indexPostOrder,inOrderStart, pos-1, n, nodeToIndex);
        
        return root;
    }
Node *buildTree(int in[], int post[], int n) {
    // Your code here
      int indexPostOrder= n-1;
        // create map for storing index of in order
        map<int, int> nodeToIndex;
        // create nodes to index map
       createMapping(in,nodeToIndex,n); 
       Node* ans= solve(in,post,indexPostOrder,0,n-1, n, nodeToIndex);
        return ans;
}