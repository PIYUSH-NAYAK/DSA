#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // Record operations as (type, index)
        // type 1 = swap a[i] and a[i+1]
        // type 2 = swap b[i] and b[i+1]
        // type 3 = swap a[i] and b[i]
        vector<pair<int,int>> ops;

        // Step 1: Ensure a[i] <= b[i] at every position by doing type-3 swaps
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
                ops.emplace_back(3, i+1);
            }
        }

        // Step 2: Sort array a with adjacent swaps (type 1)
        // Bubble‐sort style; at most n(n−1)/2 swaps.
        for (int pass = 0; pass < n; pass++) {
            for (int i = 0; i+1 < n; i++) {
                if (a[i] > a[i+1]) {
                    swap(a[i], a[i+1]);
                    ops.emplace_back(1, i+1);
                }
            }
        }

        // Step 3: Sort array b with adjacent swaps (type 2)
        for (int pass = 0; pass < n; pass++) {
            for (int i = 0; i+1 < n; i++) {
                if (b[i] > b[i+1]) {
                    swap(b[i], b[i+1]);
                    ops.emplace_back(2, i+1);
                }
            }
        }

        // Output
        // It's guaranteed that ops.size() ≤ 40 + 780 + 780 = 1600 ≤ 1709
        cout << ops.size() << "\n";
        for (auto &p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}
