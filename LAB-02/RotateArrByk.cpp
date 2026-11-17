#include <bits/stdc++.h>
using namespace std;

void reverseArray(int (&arr)[6],int i,int j){
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

void RotateArrayByk(int (&arr)[6],int n,int k){
    k=k%n;

    reverseArray(arr,0,n-1);
    reverseArray(arr,0,k);
    reverseArray(arr,k+1,n-1);


}

int main(){
    int arr[]={1,2,3,4,5,6};
    int k;
    cout<<"Enter the rotation index:";
    cin>>k;
    RotateArrayByk(arr,6,2);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }

}