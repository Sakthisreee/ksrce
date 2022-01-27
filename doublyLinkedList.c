#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head= NULL;
struct node *last= NULL;

//method to add
void add(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
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

//method to search
int search(struct node *headadd,int ele){
    while(headadd!=NULL){
        if(headadd->data==ele){
            return 1;
        }
        headadd=headadd->next;

    }
    return 0;


}

//mehod to insert
void insert(struct node *head1,int afterval,int val){
    struct node *newn=malloc(sizeof(struct node));
    newn->data=val;
    newn->next=NULL;
    newn->prev=NULL;
    while(head1!=NULL){
        if(head1->data==afterval){
            break;
        }
        head1=head1->next;
    }
    head1->next->prev=newn;
    newn->next=head1->next;
    head1->next=newn;
    newn->prev=head1;


}

//method to delete
void del(struct node *heada,int ele){
    struct node *delnode=heada;
    if(delnode->data==ele && delnode->next==NULL){
        free(delnode);
    }
    else if(delnode->data==ele){
        delnode->next->prev=NULL;
        free(delnode);
        
    }
    else {
        while(delnode!=NULL){
            if(delnode->data==ele){
                break;
            }
            delnode=delnode->next;
        }
        if(delnode->next==NULL){
            delnode->prev->next=NULL;
            free(delnode);
            
        }
        else{
            delnode->prev->next=delnode->next;
            delnode->next->prev=delnode->prev;
            free(delnode);
             
        }
    }

}

//method to print list

void print(struct node *headaddress){
    while(headaddress!=NULL){
        printf("%d ",headaddress->data);
        headaddress=headaddress->next;
    }
    printf("\n");
}

//main funcion
int main()
{
    add(77);
    add(88);
    add(8);
   
    del(head,88);
   
     print(head);
     insert(head,77,7);
    if(search(head,88)){
        printf("found\n");
    }
    print(head);
    return 0;
}
