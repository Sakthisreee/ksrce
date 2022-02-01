#include <stdio.h>
int search(int arr[],int size,int ele){
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==ele){
            return 1;
        }
        if(ele>arr[mid]){
            start=mid+1;
        }
        else
        end=mid-1;
    }
    return 0;
}

//main function
int main(){
    int arr[]={1,5,6,7,9,10,89};
    if(search(arr,7,8)){
        printf("Element Found");
    }
    else
    printf("Element Not Found");
}