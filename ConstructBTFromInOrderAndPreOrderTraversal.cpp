//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
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
    Node* solve(int in[], int pre[], int &indexp, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex){
        // base case
        if(indexp >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        // create a root node for element
        int ele=  pre[indexp++];
        Node* root = new Node(ele);
        
        // find element's index in inorder
        int pos= nodeToIndex[ele];
        // int pos= findPosition(in, ele,n);
        
        // recursive calls
        root->left= solve(in,pre,indexp,inOrderStart, pos-1, n, nodeToIndex);
        root->right= solve(in,pre, indexp, pos+1, inOrderEnd, n, nodeToIndex);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int indexP= 0;
        // create map for storing index of in order
        map<int, int> nodeToIndex;
        // create nodes to index map
       createMapping(in,nodeToIndex,n); 
       Node* ans= solve(in,pre,indexP,0,n-1, n, nodeToIndex);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends