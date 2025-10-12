#include <bits/stdc++.h>
using namespace std;
bool works(const int x, const int y, const int z) {
    for (int i = 0; i<31; i++) {
        const int bx = (x >> i) & 1;
        const int by = (y >> i) & 1;
        const int bz = (z >> i) & 1;
        bool found = false;
        for (int a = 0; a <= 1 && !found; a++) {
            for (int b = 0; b <= 1 && !found; b++) {
                for (int c = 0; c <= 1 && !found; c++) {
                    if (bx == (a&b) && by == (b&c) && bz == (a&c)) {
                        found = true;
                    }
                }
            }
        }
        if (!found) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int a,b,c;
        cin >> a >>b >>c;
        works(a,b,c) ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}
