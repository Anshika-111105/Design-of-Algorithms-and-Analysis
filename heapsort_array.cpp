#include <iostream>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void heapify(int arr[],int i,int n){
    int parent=i,left=2*i,right=(2*i)+1;
    if(left<=n && arr[left]>arr[parent]){
        parent=left;
    }
    if(right<=n && arr[right]>arr[parent]){
        parent=right;
    }
    if(parent!=i){
        swap(arr[i],arr[parent]);
        heapify(arr,parent,n);
    }
}
void heapSort(int arr[],int size){
    for(int i=size/2;i>=1;i--){
        heapify(arr,i,size);   //parent=i
    }
    for(int i=size;i>1;i--){
        swap(arr[i],arr[i]);
        heapify(arr,1,i-1);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n);
    return 0;
}