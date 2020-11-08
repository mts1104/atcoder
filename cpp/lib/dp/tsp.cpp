#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
using VI = vector<int>;
using VVI = vector<VI>;
static const int INF = 1 << 30;
// --------------------------------------------------------


static const int MAX_V = 15;
VVI dp((1 << MAX_V), VI(MAX_V, INF));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int V, E; cin >> V >> E;
    VVI G(V, VI(V, INF));
    REP(_, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }

    // dp[T][v] --> dp[S][u] に遷移 (T + {u} = S)
    // - 頂点 u は状態 S に含まれる必要がある
    // - 頂点 v は状態 T に含まれる必要があるが，
    //   そうでないときは dp[T][v] = INF なので気にせず計算可能
    dp[0][0] = 0;  // 「各頂点を1度ずつ通る」であれば出発点によらず最終結果は同じ(∵閉路)
    FOR(S, 1, (1 << V)) {
        REP(u, V) {
            if (!(S & (1 << u))) continue;
            int T = S - (1 << u);
            REP(v, V) {
                if (G[v][u] == INF) continue;
                dp[S][u] = min(dp[S][u], dp[T][v] + G[v][u]);
            }
        }
    }

    int ans = dp[(1 << V) - 1][0];
    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}
// Verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
