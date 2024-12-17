#include <bits/stdc++.h>

using namespace std;

pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<string> a;
int n, m;

vector<vector<vector<int>>> dijkstra(vector<tuple<int, int, int>> s) {
    vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(4, -1)));

    priority_queue<tuple<int, int, int, int>> pq;
    for (auto [si, sj, sd] : s) pq.push({0, si, sj, sd});
    while (!pq.empty()) {
        auto [dist, ui, uj, ud] = pq.top(); pq.pop();
        if (d[ui][uj][ud] != -1) continue;
        d[ui][uj][ud] = -dist;
        auto [di, dj] = dir[ud];
        for (auto [w, vi, vj, vd] : {
            make_tuple(1, ui + di, uj + dj, ud),
            make_tuple(1000, ui, uj, (ud + 1) % 4),
            make_tuple(1000, ui, uj, (ud + 3) % 4),
        }) {
            if (a[vi][vj] == '#') continue;
            if (d[vi][vj][vd] != -1) continue;
            pq.push({dist - w, vi, vj, vd});
        }
    }

    return d;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string ln;
    while (getline(cin, ln)) a.push_back(ln);
    n = a.size(), m = a[0].size();

    int si = -1, sj = -1, ei = -1, ej = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') si = i, sj = j;
            if (a[i][j] == 'E') ei = i, ej = j;
        }
    }

    vector<vector<vector<int>>> ds = dijkstra({make_tuple(si, sj, 0)});
    vector<vector<vector<int>>> de = dijkstra({
        make_tuple(ei, ej, 0),
        make_tuple(ei, ej, 1),
        make_tuple(ei, ej, 2),
        make_tuple(ei, ej, 3),
    });

    int dist = de[si][sj][2];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int psb = 0;
            for (int k = 0; k < 4; ++k) {
                psb |= ds[i][j][k] + de[i][j][(k + 2) % 4] == dist;
            }
            ans += psb;
        }
    }
    cout << ans << endl;

    return 0;
}
