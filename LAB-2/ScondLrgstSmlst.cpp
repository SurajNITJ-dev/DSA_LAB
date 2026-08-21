#include <bits/stdc++.h>
using namespace std;

int SecondLargest(int arr[],int n,int choice){

    if(choice==1){
        int maax=INT_MIN;
        int smax=INT_MIN;

        for(int i=0;i<n;i++){
            if(arr[i]>maax){
                smax=maax;
                maax=arr[i];
            }
            else if(arr[i]>smax){
                smax=arr[i];
            }
        }
        return smax;
    }
    else if(choice==0){
        int minm=INT_MAX;
        int smin=INT_MAX;

        for(int i=0;i<n;i++){
            if(arr[i]<minm){
                smin=minm;
                minm=arr[i];
            }
            else if(arr[i]<smin){
                smin=arr[i];
            }
        }
        return smin;
    }
    return -1;

}

int main(){
    int arr[]={4,5,1,2,3,7};
    cout<<"Second Largest element:"<<SecondLargest(arr,6,1)<<endl;
    cout<<"Second smallest element:"<<SecondLargest(arr,6,0)<<endl;
}