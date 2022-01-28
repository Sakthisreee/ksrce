#include<stdio.h>
#include<stdlib.h>
//Global declarations
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

//method to add at the end
void addEnd(int val){
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    if(head==NULL){
        new->next=new;
        head=new;
    }
    else{
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new;
        new->next=head;
    }
}
//method to search  for a element
int search(struct node *headadd,int ele){
    if(headadd==NULL){
        return 0;
    }
    else{
        struct node *temp1=headadd;
        while (temp1->next!=headadd)
        {if(temp1->data==ele)
        {
            return 1;
        }
        temp1=temp1->next;
        }
        return 0;
        
    }
}
//method to print elements of list
void print(struct node *headptr){
    struct node *temp2=headptr;
    do{
        printf("%d ",headptr->data);
        headptr=headptr->next;
    }
    while(headptr!=temp2);
}

//method to add element at first
void addFirst(int val){
struct node *newNode=malloc(sizeof(struct node));
newNode->data=val;
if(head==NULL){
    newNode->next=newNode;
    head=newNode;}
else{
    struct node *temp3=head;
    while (temp3->next!=head)
    {
       temp3=temp3->next;
    }
    temp3->next=newNode;
    newNode->next=head;
    head=newNode;
    }
}

//method to delete element from list

void del(int val){
    if(head==NULL){
        printf("Not found");
    }
    else if(head->data==val && head->next==head){
        free(head);
        head=NULL;
    }
    else if(head->data==val){
        struct node *last=head;
        struct node *temp4=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=head->next;
        head=last->next;
        free(temp4);
    }
    else{
        struct node *current=head;
        while(current->next!=NULL){
            if(current->next->data==val){
                struct node *temp5=current->next;
                current->next=current->next->next;
                free(temp5);
            }
        }
        if(current->next==NULL)
        {
            printf("Not found");
        }
    }
}
//main function
int main(){
    addEnd(34);
    addEnd(78);
    addEnd(45);
    print(head);
  if(search(head,34)){
      printf("found\n");
  }
 addFirst(4);
 addFirst(67);
 del(6);
    print(head);
}