// 1.WAP to insert or delete an element from an array

#include <bits/stdc++.h>
using namespace std;

void InsertDelNum(vector<int>&v,int num,int idx,int choice){
    int n=v.size();
    
    if(choice==1){
        v.push_back(0);
        int i=n;
        while(i>=1 && i!=idx-1){
            v[i]=v[i-1];
            i--;
        }
        v[idx]=num;
    }
    else if(choice==0){
        int i=idx;
        while(i<n-1){
            v[i]=v[i+1];
            i++;
        }
        v.resize(n-1);
    }
    else{
        cout<<"envalid input";
    }
}
//Suraj Kumar 162
int main(){
    vector<int>v={4,5,1,2,3,7};
    int choice;
    cout<<"Enter '0' to delete or '1' to insert:";
    cin>>choice;
    int idx;
    int num;
    cout<<"Enter the number and index: ";
    cin>>num>>idx;
    

    InsertDelNum(v,num,idx,choice);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }


}