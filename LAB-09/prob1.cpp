
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> mx, mn;

    int left = 0, ans = 0;

    for (int right = 0; right < n; right++) {

        while (!mx.empty() && a[mx.back()] < a[right])
            mx.pop_back();

        while (!mn.empty() && a[mn.back()] > a[right])
            mn.pop_back();

        mx.push_back(right);
        mn.push_back(right);

        while (a[mx.front()] - a[mn.front()] > k) {

            if (mx.front() == left)
                mx.pop_front();

            if (mn.front() == left)
                mn.pop_front();

            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans;

    return 0;
}
