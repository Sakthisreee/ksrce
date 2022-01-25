#include <stdio.h>
char* a(int a[],int size,int ele){
    for(int i=0;i<size;i++){
        if(a[i]==ele){
            return "found";
        }
    }
    
    return "not found";
}
int main(){
    int arr[]={1,2,3,4,5};
    printf("%s",a(arr,5,4));
   
    
}
