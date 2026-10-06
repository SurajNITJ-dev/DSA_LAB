#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

string removeGroups(string board) {
    bool foundGroup = true;
    while (foundGroup) {
        foundGroup = false;
        int n = board.length();
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && board[j] == board[i]) {
                j++;
            }
            if (j - i >= 3) {
                board = board.substr(0, i) + board.substr(j);
                foundGroup = true;
                break;
            } else {
                i = j;
            }
        }
    }
    return board;
}

int dfs(string board, unordered_map<char, int>& handMap) {
    board = removeGroups(board);
    if (board.empty()) return 0;

    int minBallsUsed = INT_MAX;
    int n = board.length();

    for (int i = 0; i < n; i++) {
        char c = board[i];
        
        int j = i;
        while (j < n && board[j] == c) {
            j++;
        }
        int count = j - i;
        int needed = 3 - count;

        if (handMap[c] >= needed) {
            handMap[c] -= needed;
            
            string newBoard = board.substr(0, i) + string(needed, c) + board.substr(i + count);
            int res = dfs(newBoard, handMap);
            
            if (res != -1) {
                minBallsUsed = min(minBallsUsed, res + needed);
            }
            
            handMap[c] += needed;
        }

        i = j - 1;
    }

    return (minBallsUsed == INT_MAX) ? -1 : minBallsUsed;
}

int findMinStep(string board, string hand) {
    unordered_map<char, int> handMap;
    for (char c : hand) {
        handMap[c]++;
    }
    return dfs(board, handMap);
}

int main() {
    string board1 = "WWRRBBWW";
    string hand1 = "WRBRW";
    cout<< findMinStep(board1, hand1) << endl;

    string board2 = "WRRBBW";
    string hand2 = "RB";
    cout << findMinStep(board2, hand2) << endl;

    return 0;
}