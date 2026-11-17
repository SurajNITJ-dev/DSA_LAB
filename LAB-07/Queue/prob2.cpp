#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDo(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        int m = workers.size();
        deque<int> dq;
        int ptr = 0;

        for (int i = m - k; i < m; i++) {
            int w = workers[i];

            while (ptr < k && tasks[ptr] <= w + strength) {
                dq.push_back(tasks[ptr]);
                ptr++;
            }

            if (dq.empty()) return false;

            if (dq.front() <= w) {
                dq.pop_front();
            } else {
                if (pills == 0) return false;
                pills--;
                dq.pop_back();
            }
        }
        return true;
    }

    int maxTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int n = tasks.size();
        int m = workers.size();

        int low = 0, high = min(n, m), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canDo(tasks, workers, pills, strength, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    int pills = 1;
    int strength = 1;

    Solution solver;
    cout<<"tasks = [3, 2, 1]"<<endl;
    cout<<"workers = [0, 3, 3]"<<endl;
    cout << "Largest task can be completed : " << solver.maxTasks(tasks, workers, pills, strength) << "\n";

    return 0;
}