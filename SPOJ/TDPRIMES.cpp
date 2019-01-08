#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e8;

bitset<N> np;
vector<int> out;

void sieve() {
    out.push_back(2);
    np[0] = np[1] = 1;
    np[2] = 0;
    for (int i = 3; i < N; i += 2) {
        if (!np[i]) {
            out.push_back(i);
            for (int j = i + i; j < N; j += i)
                np[j] = 1;
        }
    }    
}

int main() {
    sieve();
    for (int i = 0; i < out.size(); i += 100)
        printf("%d\n", out[i]);
    return 0;
}
