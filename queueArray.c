#include<stdio.h>
int front=0,last=0;
int arr[10];
void enqueue(int val){
    if(last==10){
        printf("Queue is full");
    }
    else{
        arr[last]=val;
        last++;
    }
}
void dequeue(){
    if(front==last){
        printf("Queue is empty");
    }
    else{
        printf("dequeued element: %d",arr[front]);
        front++;

    }
}
int main(){
    for(int i=1;i<10;i++){
        enqueue(i);
    }
    dequeue();

}
