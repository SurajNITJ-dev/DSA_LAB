 #include <bits/stdc++.h>
using namespace std;

int FindPindx(vector<int>& v,int lo,int hi){

    int pvtElmnt=v[lo];
    int i=lo;
    int j=hi;

    while(i<j){

        while(v[i]<=pvtElmnt && i<hi){
            i++;
        }
        while(v[j]>pvtElmnt && j>=lo+1){
            j--;
        }

        if(i<j){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
        }
    }

    int temp=v[lo];
            v[lo]=v[j];
            v[j]=temp;
    return  j;
}

vector<int>QuickSort(vector<int>& v,int lo,int hi){
    
    if(lo<hi){

        int pvot=FindPindx(v,lo,hi);
        QuickSort(v,lo,pvot-1);
        QuickSort(v,pvot+1,hi);
    }
    return v;
}



    int main(){
        int n;
        cin>>n;
        vector<int>nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        QuickSort(nums,0,n-1);

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        
    }
    