#include <stdio.h>
#include<stdlib.h>
//Global declarations
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *last;

//method to add element
void add(int val){
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

//method to delete
void del(struct node *headtodel,int ele){
    struct node *temp1; 
    if(headtodel->data==ele){
        temp1=headtodel;
        headtodel=headtodel->next;
        free(temp1);
        
    }
      else{  struct node *currentNode=headtodel;
        while(currentNode->next!=NULL){
            if(currentNode->next->data==ele){
                temp1=currentNode->next;
                currentNode->next=currentNode->next->next;
                free(temp1);
              
            }
            else
            currentNode=currentNode->next;
        }     
    }

}

//method to insert
void insert(struct node *head,int afterele,int ele){
    struct node *new=malloc(sizeof(struct node));
    new->data=ele;
    struct node *temp2=head;
    while(temp2->next!=NULL){
          if(temp2->data==afterele){
                new->next=temp2->next;
                temp2->next=new;
                return;
               
          }
          temp2=temp2->next;
    }

}

//method to print
void print(struct node *headaddress){
    while(headaddress!=NULL){
        printf("%d ",headaddress->data);
        headaddress=headaddress->next;
    }
    printf("\n");
}


//method to search

int isPresent(struct node *headnode,int ele){
    while(headnode!=NULL){
        if(headnode->data==ele)
        {
        return 1;}
        headnode=headnode->next;
    }
    return -1;

}

//main function
int main(){
    add(78);
    add(7);
    add(76);
    add(2);
    add(3);
   print(head);
    del(head,7);
   
    print(head);
     insert(head,76,9);
     print(head);
    if(isPresent(head,7)){
        printf("\nfound");
    return 0;
    }
}