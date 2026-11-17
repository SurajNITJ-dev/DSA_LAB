
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

bool canComplete(vector<int>& tasks, vector<int>& workers,
                 int pills, int strength, int k) {

    deque<int> q;

    int j = workers.size() - k;

    for (int i = 0; i < k; i++) {

        int task = tasks[i];

        while (j < workers.size() && workers[j] + strength >= task) {
            q.push_back(workers[j]);
            j++;
        }

        if (q.empty())
            return false;

        if (q.front() >= task) {
            q.pop_front();
        }
        else {
            if (pills == 0)
                return false;

            pills--;
            q.pop_back();
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> tasks(n), workers(m);

    for (int i = 0; i < n; i++)
        cin >> tasks[i];

    for (int i = 0; i < m; i++)
        cin >> workers[i];

    int pills, strength;
    cin >> pills >> strength;

    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int low = 0, high = min(n, m);
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canComplete(tasks, workers, pills, strength, mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
