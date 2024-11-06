// consider a circular linked list with a pointer pointing to its head write a c function to delete a node from the circular linked list (consider all the cases)
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertNode(struct node **head,int data){
    struct node *newnode = createNode(data);
    if(*head==NULL){
        *head=newnode;
    }else{
        struct node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
}

struct node deleatNodeBeg(struct node **head){
    struct node *temp=*head;
    if(*head==NULL){
        printf("list is empty!");
    }else{
        *head=(*head)->next;
        (*head)->prev=NULL;
    }
    free(temp);
}

void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node *head=NULL;
    insertNode(&head,10);
    insertNode(&head,20);
    insertNode(&head,30);
    insertNode(&head,40);
    insertNode(&head,50);
    printf("\nlist before deleat from begining!\n");
    display(head);
    
    printf("\nlist after deleat from begining!\n");
    deleatNodeBeg(&head);
    display(head);

    return 0;
}