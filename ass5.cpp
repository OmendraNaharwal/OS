#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter processes and resources: ";
    cin >> n >> m;

    int alloc[n][m], maxm[n][m], need[n][m], avail[m];
    bool finish[n] = {};

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxm[i][j];

    cout << "Enter Available Resources:\n";
    for (int j = 0; j < m; j++)
        cin >> avail[j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    int count = 0, safe[n];

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can = true;

                for (int j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        can = false;

                if (can) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "System is NOT in Safe State";
            return 0;
        }
    }

    cout << "System is in Safe State\nSafe Sequence: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safe[i] << " ";

    return 0;
}
