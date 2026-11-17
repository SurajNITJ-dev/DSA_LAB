#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPassengers(vector<int>& stress, int K) {
        int n = stress.size();
        deque<int> maxQ;   
        deque<int> minQ;   

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
           
            while (!maxQ.empty() && stress[maxQ.back()] <= stress[right])
                maxQ.pop_back();
            maxQ.push_back(right);

           
            while (!minQ.empty() && stress[minQ.back()] >= stress[right])
                minQ.pop_back();
            minQ.push_back(right);


            while (stress[maxQ.front()] - stress[minQ.front()] > K) {
                left++;
                if (maxQ.front() < left) maxQ.pop_front();
                if (minQ.front() < left) minQ.pop_front();
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    int n, K;
    cout << "Enter size of array stress (n): ";
    cin >> n;

    vector<int> stress(n);
    cout << "Enter stress values: ";
    for (int i = 0; i < n; i++) cin >> stress[i];

    cout << "Enter threshold K: ";
    cin >> K;

    Solution solver;
    cout << " maximum consecutive passengers can board together : " << solver.maxPassengers(stress, K) << "\n";

    return 0;
}