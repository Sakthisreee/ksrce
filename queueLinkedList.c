#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;
void enqueue(int val){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL && last==NULL){
        head=newnode;
        last=newnode;
    }
    else{
        last->next=newnode;
        last=newnode;
    }
   
}

void dequeue()
{ struct node *temp=head;
    if(head==NULL){
        printf("queue is empty.");
    }
    else{
        printf("dequeued element: %d\n",head->data);
        head=head->next;
        free(temp);

    }
    if(head==NULL){
        last=NULL;
    }

}
int main()
{
  for(int i=1;i<8;i++){
      enqueue(i);
  }
  dequeue();
  dequeue();

}