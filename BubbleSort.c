#include <stdio.h>
//functiono sort array

void sort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//main function
int main()
{
    int arr[]={1,6,4,7,3,7};
    sort(arr,6);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}