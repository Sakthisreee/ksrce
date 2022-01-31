#include <stdio.h>
int temp=-1;
int arr[10];
void push(int val){
    if(temp>=10){
        printf("Stack is full");
    }
    else{
        arr[++temp]=val;

    }
}
void pop(){
    if(temp<0){
        printf("Stack  is empty");
    }
    else{
        printf("popped element: %d\n",arr[temp]);
        temp--;
    }
}
int main(){
    for(int i=0;i<10;i++){
        push(i);
    }
    pop();
    pop();

} 