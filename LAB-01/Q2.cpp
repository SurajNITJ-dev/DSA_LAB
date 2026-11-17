#include <iostream>
using namespace std;

void printSubsetsWithTargetSum(int nums[], int n, int target) {
    int m = 1 << n; 

    for (int i = 0; i < m; i++) {
        int sum = 0;

        
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += nums[j];
            }
        }

        
        if (sum == target) {
            cout << "{ ";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cout << nums[j] << " ";
                }
            }
            cout << "}\n";
        }
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 5;

    cout << "Subsets with sum equal to " << target << ":" << endl;
    printSubsetsWithTargetSum(nums, n, target);

    return 0;
}