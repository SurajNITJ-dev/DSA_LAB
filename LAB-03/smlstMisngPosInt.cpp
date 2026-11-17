#include <iostream>

using namespace std;


int findSmallestMissingPositive(int arr[], int n) {
    
 
    for (int i = 0; i < n; i++) {
        
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
          
            int correctIndex = arr[i] - 1;
            int temp = arr[i];
            arr[i] = arr[correctIndex];
            arr[correctIndex] = temp;
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

   
}

int main() {
  
    int arr1[] = {3, 4, -1, 1}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    cout << "smallest missing positive is: " 
         << findSmallestMissingPositive(arr1, n1) << endl;

 

    return 0;
}