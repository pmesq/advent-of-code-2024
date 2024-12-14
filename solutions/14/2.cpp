#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const int n = 103, m = 101;

    vector<tuple<int, int, int, int>> a;

    string ln;
    while (getline(cin, ln)) {
        int cnt = 0;
        vector<int> b(4);
        string cur;
        for (int i = 0; i < (int) ln.size(); ++i) {
            if (ln[i] == ',' || ln[i] == ' ') {
                b[cnt] = stoi(cur);
                cur = "";
                ++cnt;
            } else if (isdigit(ln[i]) || ln[i] == '-') {
                cur.push_back(ln[i]);
            }
        }
        b[cnt] = stoi(cur);
        a.emplace_back(b[0], b[1], b[2], b[3]);
    }

    for (int t = 0; t < 10000; ++t) {
        vector<vector<int>> g(n, vector<int>(m, 0));
        for (auto&[x, y, vx, vy] : a) {
            x = ((x + vx) % m + m) % m;
            y = ((y + vy) % n + n) % n;
            g[y][x]++;
        }
        const int K = 10;
        int fnd = 0;
        for (int i = 0; i + K < n; ++i) {
            for (int j = 0; j + K < m; ++j) {
                int psb = 1;
                for (int k = 0; k < K; ++k) {
                    if (g[i + k][j + k] == 0) {
                        psb = 0;
                    }
                }
                if (psb) {
                    fnd = 1;
                    break;
                }
            }
        }
        if (fnd) {
            cout << t + 1 << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout<<g[i][j];
                }
                cout<<endl;
            }
            cout<<"---"<<endl;
        }
    }

    return 0;
}
