#include <iostream>

using namespace std;

void findEquilibriumIndices(const int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    long long left_sum = 0;
    bool found = false;

    cout << "Equilibrium indices: ";

   
    for (int i = 0; i < n; i++) {
        
        long long right_sum = total_sum - left_sum - arr[i];

        if (left_sum == right_sum) {
            cout << i << " ";
            found = true;
        }

        left_sum += arr[i];
    }

    if (!found) {
        cout << "None";
    }
    cout << endl;
}

int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    findEquilibriumIndices(arr, n);

    return 0;
}