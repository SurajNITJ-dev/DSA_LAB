#include <bits/stdc++.h>
using namespace std;

void CmpMerg(vector<int>& v, int lo, int mid, int hi, vector<int>& temp){
        int tindx = lo;
        int lft = lo;
        int rit = mid + 1;

        while(lft <= mid && rit <= hi){
            if(v[lft] >= v[rit]){
                temp[tindx] = v[rit];
                tindx++;
                rit++;
            }
            else{
                temp[tindx] = v[lft];
                tindx++;
                lft++;
            }
        }
        
        while(lft <= mid){
            temp[tindx] = v[lft];
            tindx++;
            lft++;
        }
        while(rit <= hi) {
            temp[tindx] = v[rit];
            tindx++;
            rit++;
        }

        for(int i = lo; i <= hi; i++){
            v[i] = temp[i];
        }
    } 

    void MergSort(vector<int>& v, int lo, int hi, vector<int>& temp){
        if(lo >= hi) return;

        int mid = lo + (hi - lo) / 2;
        MergSort(v, lo, mid, temp);
        MergSort(v, mid + 1, hi, temp);
        CmpMerg(v, lo, mid, hi, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
     
        int n = nums.size();
        vector<int> temp(n); 
        MergSort(nums, 0, n - 1, temp);

        return nums;  
    }

int main(){
        int n;
        cout<<"Enter size of array : ";
        cin>>n;
        vector<int>nums(n);
        cout<<"Enter numbers in array : ";
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        vector<int> temp(n); 
        MergSort(nums, 0, n - 1, temp);

        cout<<"Sorted using Merge Sort : ";
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        
    }