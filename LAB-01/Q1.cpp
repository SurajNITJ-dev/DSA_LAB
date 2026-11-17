#include <iostream>
using namespace std;

void rearrangeArray(int nums[], int ans[], int n) {
    int evn = 0;
    int odd = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[evn] = nums[i];
            evn += 2;
        } else {
            ans[odd] = nums[i];
            odd += 2;
        }
    }
}

int main() {
    int nums[] = {3, 1, -2, -5, 2, -4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int ans[n];

    rearrangeArray(nums, ans, n);

    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout <<endl;

    return 0;
}