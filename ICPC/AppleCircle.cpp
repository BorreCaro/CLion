#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, uglyCount= 0; cin >> n;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (s.contains(x)) uglyCount++; else s.insert(x);
        }
        cout<<n-uglyCount<<"\n";
    }
    return 0;
}