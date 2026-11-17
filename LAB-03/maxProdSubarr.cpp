#include <iostream>
#include <algorithm>

using namespace std;

int maxProductSubarray(int arr[], int n) {
    if (n == 0) return 0;

    int max_so_far = arr[0];
    int min_so_far = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        int curr = arr[i];

        
        if (curr < 0) {
            swap(max_so_far, min_so_far);
        }

        max_so_far = max(curr, max_so_far * curr);
        min_so_far = min(curr, min_so_far * curr);

        result = max(result, max_so_far);
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 3, -1, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Product Subarray: " << maxProductSubarray(arr, n) << endl;

    return 0;
}









// #include <iostream>
// #include <limits.h>
// #include <bits/stdc++.h>

// using namespace std;

// int main(){

//     int arr[8]={1,2,3,-1,2,3-2,3};
//     int maxProd=INT_MIN;
//     int countNeg=0; 
//     for(int i=0;i<8;i++){
//         if(arr[i]<0) countNeg++;
//     }
//     vector<vector<int>>ans;
    
//     int i=0;
//     int j=i;
//     int prod=1;
//     int idx=0;
//     int maxProd=INT_MIN;
//     while(j<8 && i<8){
//         vector<int>temp;
//         if(arr[j]==0){
//             i=j+1;
            
//             if(maxProd<prod){
//                 ans.push_back(temp);
//                 idx++;
//             }
//             prod=1;
            
//         }
//         if(arr[j]<0 && prod>0){
//             if(countNeg>=2){
//                 temp.push_back(arr[j]);
//             }else{
//                 i=j+1;
//                 if(maxProd<prod){
//                 ans.push_back(temp);
//                 idx++;
//             }
//                 prod=1;
//             }
//         }
//         else if(arr[j]<0 && prod<0){
//             if(countNeg>=1){
//                 temp.push_back(arr[j]);
//             }
//             else{
//                 i=j+1;
//                 if(maxProd<prod){
//                 ans.push_back(temp);
//                 idx++;
//             }
//                 prod=1;
//             }

//         }
        
//     }

// }