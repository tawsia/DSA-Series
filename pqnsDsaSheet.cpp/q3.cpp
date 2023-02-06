
// rearrange a linked list in zigzag fashion 
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node* next;
};


void zigZag(Node* head){
    bool flag = true;

    Node* curr= head;

    while(curr->next != NULL){
        if(flag){
            if(curr->data > curr->next->data){
                swap(curr->data, curr->next->data);
            }
        }
            else {
                if(curr->data < curr->next->data){
                    swap(curr->data, curr->next->data);
                }
            }
            curr= curr->next;

            flag = !flag;
        
    }
}
void push(Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = new Node;
 
    /* put in the data  */
    new_Node->data = new_data;
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}
 
/* Function to print linked list */
void printList(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d->", Node->data);
        Node = Node->next;
    }
    printf("NULL");
}
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // create a list 4 -> 3 -> 7 -> 8 -> 6 -> 2 -> 1
    // answer should be -> 3  7  4  8  2  6  1
    push(&head, 1);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);
 
    printf("Given linked list \n");
    printList(head);
 
    zigZag(head);
 
    printf("\nZig Zag Linked list \n");
    printList(head);
 
    return (0);
}