#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    string clean(string s) {
        bool changed = true;
        while (changed) {
            changed = false;
            int i = 0;
            string res = "";
            while (i < (int)s.size()) {
                int j = i;
                while (j < (int)s.size() && s[j] == s[i]) j++;
                if (j - i >= 3) changed = true;     
                else res += s.substr(i, j - i);      
                i = j;
            }
            s = res;
        }
        return s;
    }

    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());

        queue<pair<string, string> > q;       
        set<pair<string, string> > visited;

        q.push(make_pair(board, hand));
        visited.insert(make_pair(board, hand));

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                string b = q.front().first;
                string h = q.front().second;
                q.pop();

                for (int i = 0; i < (int)h.size(); i++) {
                    if (i > 0 && h[i] == h[i - 1]) continue;  

                    string newHand = h.substr(0, i) + h.substr(i + 1);

                    for (int j = 0; j <= (int)b.size(); j++) {
                       
                        if (j > 0 && b[j - 1] == h[i]) continue;

                        bool ok = false;
                        if (j < (int)b.size() && b[j] == h[i]) ok = true;
                        if (j > 0 && j < (int)b.size() && b[j - 1] == b[j] && b[j] != h[i]) ok = true;
                        if (!ok) continue;

                        string newBoard = clean(b.substr(0, j) + h[i] + b.substr(j));

                        if (newBoard.empty()) return steps;

                        if (!visited.count(make_pair(newBoard, newHand))) {
                            visited.insert(make_pair(newBoard, newHand));
                            q.push(make_pair(newBoard, newHand));
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    string board, hand;

    cout << "Enter board: ";
    cin >> board;
    cout << "Enter hand: ";
    cin >> hand;

    Solution solver;
    int ans = solver.findMinStep(board, hand);
    cout << "Output: " << ans << "\n";

    return 0;
}