#include<stdio.h>
void sort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

//main function
int main()
{
    int arr[]={3,1,0,8,90,6};
    sort(arr,6);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}