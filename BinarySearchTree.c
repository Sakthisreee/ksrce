#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root=NULL;

//function to create newnode
struct node *newNode(int val){
    struct node *new=malloc(sizeof(struct node));
    new->left=NULL;
    new->right=NULL;
    new->data=val;
}

//function to insert newnode

struct node *insert(struct node* root,int val){
    if(root==NULL){
        return newNode(val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
    }
    return root;
}


//function to search for a data
int search(struct node *root,int ele)
{
    if(root==NULL){
        return 0;
    }
     if(root->data ==ele){
        return 1;
    }
   else if(ele<root->data){
       search(root->left,ele);
    }
    else if(ele>root->data){
        search(root->right,ele);
    }

}
//printing elements of the tree
void display(struct node *root){
    if(root==NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
}
int getMax(struct node *root){
    struct node *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
//funcion to delete an element from the tree
struct node *delete(struct node *root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val>root->data){
        root->right=delete(root->right,val);
    }
    else if(val<root->data){
        root->left=delete(root->left,val);
    }
    else{
        if(root->right==NULL && root->left==NULL){
            free(root);
            return NULL;
        }
        else if(root->right==NULL){
            struct node *temp1=root->left;
            free(root);
            return temp1;
        }
        else if(root->left==NULL){
            struct node *temp1=root->right;
            free(root);
            return temp1;
        }
        else{
            int leftMax=getMax(root->left);
            root->data=leftMax;
            root->left=delete(root->left,leftMax);
        }
    }
    return root;
}






//main function
int main()
{
    root=insert(root,70);
    insert(root,67);
    insert(root,89);
    insert(root,56);
    if(search(root,67)){
        printf("Found\n");
    }
    else{
        printf("Not found\n");
    }
    delete(root,89);
    display(root);
    return 0;
}
