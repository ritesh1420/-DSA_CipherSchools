#include <iostream>
using namespace std;

void merge(int arr[] , int s, int m , int e){
    int n1 = m-s+1;
    int n2 = e-m;
    int arr1[n1];
    int arr2[n2];
    
    for(int i=0; i<n1;i++){
        arr1[i] = arr[s+i];
    }
    for(int j=0; j<n2;j++){
        arr2[j] = arr[m+1+j];
    }
    int i=0;
    int j=0;
    int c = s;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[c] = arr1[i];
            i++;c++;
        }else{
            arr[c]= arr2[j];
            j++;
            c++;
        }
    }
    while(i<n1){
        arr[c] = arr1[i];
        i++;
        c++;
    }
    while(j<n2){
        arr[c] = arr2[j];
        c++;
        j++;
    }
}
void sortMerge(int arr[] , int s, int e){
    if(s<e){
        int m = s +(e-s)/2;
    sortMerge(arr,s,m);
    sortMerge(arr,m+1,e);
    merge(arr,s,m,e);}
}


int main() {
   int arr[] = {12,45,67,78,3,56,34};
   sortMerge(arr,0,6);
   for(int i=0; i <7;i++){
       cout<<arr[i]<<" ";
   }

    return 0;
}
