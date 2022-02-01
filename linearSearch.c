#include <stdio.h>
int search(int arr[],int size,int ele){
    for(int i=0;i<size;i++){
        if(arr[i]==ele){
            return 1;
        }}
        return 0;
}

//main function
int main(){
    int arr[]={3,7,3,7,90,67,5,78};
    if(search(arr,8,78)){
        printf("Search found");
    }
    else
    printf("Search Not Found");
} 