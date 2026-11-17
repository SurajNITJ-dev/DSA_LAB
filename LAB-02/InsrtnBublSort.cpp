//Suraj Kumar 162
#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int (&arr)[6],int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=1 && arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

void BubbleSort(int (&arr)[6],int n){

    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=false;;
            }
            
        }
        if(flag) break;
    }
}

int main(){

    int arr[6]={4,5,1,2,3,7};
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Sorting Using Insertion Sort"<<endl;
    InsertionSort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Sorting Using Bubble Sort"<<endl;
    BubbleSort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}