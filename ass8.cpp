#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter requests: ";
    for (int &x : a) cin >> x;

    cout << "Enter head position: ";
    cin >> head;

    // SSTF
    vector<int> b = a;
    int h = head, total = 0;
    cout << "\nSSTF: " << h;
    while (!b.empty()) {
        int k = 0;
        for (int i = 1; i < b.size(); i++)
            if (abs(b[i] - h) < abs(b[k] - h) || 
               (abs(b[i] - h) == abs(b[k] - h) && b[i] < b[k]))
                k = i;

        total += abs(b[k] - h);
        h = b[k];
        cout << " -> " << h;
        b.erase(b.begin() + k);
    }
    cout << "\nTotal Head Movement = " << total << endl;

    // SCAN (moving toward higher cylinders)
    sort(a.begin(), a.end());
    total = 0; h = head;
    cout << "\nSCAN: " << h;
    for (int x : a)
        if (x >= head) {
            total += abs(x - h);
            h = x;
            cout << " -> " << h;
        }
    total += abs(199 - h);
    h = 199;
    cout << " -> " << h;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] < head) {
            total += abs(a[i] - h);
            h = a[i];
            cout << " -> " << h;
        }
    cout << "\nTotal Head Movement = " << total << endl;

    // C-LOOK
    total = 0; h = head;
    cout << "\nC-LOOK: " << h;
    for (int x : a)
        if (x >= head) {
            total += abs(x - h);
            h = x;
            cout << " -> " << h;
        }
    for (int x : a)
        if (x < head) {
            if (h == head) {
                total += abs(a[0] - h);
                h = a[0];
                cout << " -> " << h;
            }
            total += abs(x - h);
            h = x;
            cout << " -> " << h;
        }
    cout << "\nTotal Head Movement = " << total << endl;

    return 0;
}
