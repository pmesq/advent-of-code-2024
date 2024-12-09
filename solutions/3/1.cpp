#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string a;
    string ln;
    while (getline(cin, ln)) a += ln;
    int n = a.size();
    long long ans = 0;
    int p = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '(') p = i;
        if (a[i] != ')') continue;
        if (p == -1) continue;
        if (p < 3 || a[p - 3] != 'm' || a[p - 2] != 'u' || a[p - 1] != 'l') continue;
        if (i - p > 8) continue;
        int q = -1;
        for (int j = p + 1; j < i; ++j) {
            if (a[j] == ',') q = j;
        }
        if (q == -1) continue;
        if (i - q > 4 || q - p > 4) continue;
        int psb = 1;
        int u = 0, v = 0;
        for (int j = p + 1; j < q; ++j) {
            if (!isdigit(a[j])) psb = 0;
            u *= 10;
            u += a[j] - '0';
        }
        for (int j = q + 1; j < i; ++j) {
            if (!isdigit(a[j])) psb = 0;
            v *= 10;
            v += a[j] - '0';
        }
        if (!psb) continue;
        ans += u * v;
    }
    cout << ans << endl;

    return 0;
}
