#include <bits/stdc++.h>

using namespace std;

int f(vector<int>&a) {
    int neg = 0;
    for (int i = 1; i < (int) a.size(); ++i) {
        int d = a[i] - a[i - 1];
        if (d == 0 || abs(d) > 3) return 0;
        if (d < 0) ++neg;
    }
    return neg == 0 || neg == (int) a.size() - 1;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int ans = 0;
    string ln;
    while (getline(cin, ln)) {
        stringstream ss(ln);
        vector<int> a;
        int x;
        while (ss >> x) {
            a.push_back(x);
        }
        int psb = f(a);
        for (int i = 0; i < (int) a.size(); ++i) {
            int x = a[i];
            a.erase(a.begin() + i);
            psb |= f(a);
            a.insert(a.begin() + i, x);
        }
        ans += psb;
    }
    cout << ans << endl;

    return 0;
}
