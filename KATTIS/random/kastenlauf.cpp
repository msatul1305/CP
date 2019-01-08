#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define X first
#define Y second

const int N = 105;

class uf {
    int par[N];
  public:
    uf() {
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int get(int a) {
        return par[a] == a ? a : par[a] = get(par[a]);
    }
    void merge(int a, int b) {
        par[get(a)] = get(b);
    }
};

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        vector< pair<int, int> > points;
        uf ds;
        scanf("%d", &n);
        for (int i = 0; i < n + 2; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            points.push_back({x, y});
        }
        bool ans = 1;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) if (i != j) {
                if (abs(points[i].X - points[j].X) + abs(points[i].Y - points[j].Y) <= 1000)
                    ds.merge(i, j);
            }
        }
        if (ds.get(0) == ds.get(n + 1))
            puts("happy");
        else
            puts("sad");
    }
    return 0;
}
