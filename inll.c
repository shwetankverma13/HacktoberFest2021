#include<stdio.h>

void show(int a[],int b){
    printf("Element in array are\n");
    for(int i=0;i<b;i++){
        printf("The Element at %d index\n",i);
        printf("%d\n",a[i]);
    }
}
void fill(int a[],int b){
    
    for(int i=0;i<b;i++){
        printf("Enter The Element at %d index\n",i);
        scanf("%d\n",&a[i]);
    }
}
int insert(int a[],int b,int c,int n,int ip){
    if (b>=c){
        return b;
    }
    else{
        for(int i=b-1;i>=ip;--i){
            a[i+1]=a[i];
        }
        return b+1;
        a[ip]=n;
    }
}
int main(){
    int n;int m;int no;int in;
    printf("Enter the total size of arr");
    scanf("ENter:%d\n",&n);
    printf("m is the total element of arr");
    scanf("Enter m: %d\n",&m);
    int arr[n];
    fill(arr,m);
    show(arr,m);
    printf("Enter the no you want to insert in arr");
    scanf("ENter  :%d\n",&no);
    printf("Enter the index at which you want to insert the no");
    scanf("ENter  :%d\n",&in);
    m=insert(arr,m,n,no,in);
    return 0;
}
