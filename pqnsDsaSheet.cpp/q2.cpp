
// flatten a multilevl linked list 

#include<bits/stdc++.h>
using namespace std;

// Macro to find number of elements in array 
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

class Node 
{ 
    public:
    int data; 
    Node *next; 
    Node *child; 
}; 
  
// A utility function to create a linked list
// with n nodes. The data of nodes is taken 
// from arr[]. All child pointers are set as NULL 
Node *createList(int *arr, int n) 
{ 
    Node *head = NULL; 
    Node *p; 
  
    int i; 
    for (i = 0; i < n; ++i) 
    { 
        if (head == NULL) 
            head = p = new Node();
        else 
        { 
            p->next = new Node();
            p = p->next; 
        } 
        p->data = arr[i]; 
        p->next = p->child = NULL; 
    } 
    return head; 
} 
void printList(Node *head) 
{ 
    while (head != NULL) 
    { 
        cout << head->data << " "; 
        head = head->next; 
    } 
    cout<<endl; 
} 
Node *createList(void) 
{ 
    int arr1[] = {10, 5, 12, 7, 11}; 
    int arr2[] = {4, 20, 13}; 
    int arr3[] = {17, 6}; 
    int arr4[] = {9, 8}; 
    int arr5[] = {19, 15}; 
    int arr6[] = {2}; 
    int arr7[] = {16}; 
    int arr8[] = {3}; 
  
    /* create 8 linked lists */
    Node *head1 = createList(arr1, SIZE(arr1)); 
    Node *head2 = createList(arr2, SIZE(arr2)); 
    Node *head3 = createList(arr3, SIZE(arr3)); 
    Node *head4 = createList(arr4, SIZE(arr4)); 
    Node *head5 = createList(arr5, SIZE(arr5)); 
    Node *head6 = createList(arr6, SIZE(arr6)); 
    Node *head7 = createList(arr7, SIZE(arr7)); 
    Node *head8 = createList(arr8, SIZE(arr8)); 
  
  
    /* modify child pointers to 
    create the list shown above */
    head1->child = head2; 
    head1->next->next->next->child = head3; 
    head3->child = head4; 
    head4->child = head5; 
    head2->next->child = head6; 
    head2->next->next->child = head7; 
    head7->child = head8; 
  
  
    /* Return head pointer of first 
    linked list. Note that all nodes are 
    reachable from head1 */
    return head1; 
} 

void flatten(Node* head){
    // base case
    if(head== NULL){
        return ;
    }

    Node* temp;

// find tail pointer
    Node* tail= head;
    while(tail->next != NULL){
        tail= tail->next;
    }

    Node* curr= head;
// traverse all nodes of first level till we reach tail node
    while(curr != tail){
        // if curr has child
        if(curr->child){
            tail->next= curr->child;

        //  update tail to new last node
        temp = curr->child;
        while(temp->next){
            temp = temp->next;
            tail= temp;
        }
       }
       curr= curr->next;
    }
}

int main(){

  Node *head = NULL; 
    head = createList(); 
    flatten(head); 
    printList(head); 
    return 0;



    return 0;
}