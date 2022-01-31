#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;

//push into the stack
void push(int val){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL && last==NULL){
        head=newnode;
        last=newnode;
    }
    else{
        last->next=newnode;
        newnode->prev=last;
        last=newnode;
    }
}
void pop(){
    if(head==NULL  && last==NULL){
        printf("Stack is empty\n");
    }
    else if(last->prev==NULL && last->next==NULL){
        printf("Poppped element: %d\n",last->data);
        free(last);
        head=NULL;
        last=NULL;
    }

    else{
        printf("Poppped element: %d\n",last->data);
        struct node *temp=last;
        last->prev->next=NULL;
        last=last->prev;
        printf("d",last->prev);
        free(temp);
    }
}

int main(){
    push(18);
    pop();
    pop();
    pop();
}