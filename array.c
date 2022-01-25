#include <stdio.h>
int* removes(int arr[],int* size,int ele){
    
    int index;
    for(int i=0;i<(*size);i++){
        if(arr[i]==ele){
            index=i;
        }
    }
    for(int j=index;j<(*size)-1;j++){
        arr[j]=arr[j+1];
    }
    (*size)--;
    return arr;
}


int main()
{   int size=5;
    int a[size];
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    removes(a,&size,3);
   for(int i=0;i<size;i++){
       printf("%d ",a[i]);
   }

    return 0;
}
