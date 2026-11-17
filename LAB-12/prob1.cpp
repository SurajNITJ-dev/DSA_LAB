#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Max Heap : ";
    for (auto it : arr) {
        cout << it << " ";
    }
    cout << endl;

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter no. of elements in heap : ";
    cin >> n;

    vector<int> v(n);
    cout<<"\nEnter all the elements with space : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    heapSort(v, n);

    cout << "Sorted using Heap Sort : ";
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}