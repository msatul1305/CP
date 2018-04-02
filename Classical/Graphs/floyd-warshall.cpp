#include <bits/stdc++.h>
using namespace std;

const int inf = 999;

int n;
int adj[100][100];
int dis[100][100];

void inp() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
}

void init() {
	inp();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j)
				dis[i][j] = 0;
			else if(adj[i][j])
				dis[i][j] = adj[i][j];
			else
				dis[i][j] = inf;
		}
	}
}

void flowr() {
	init();
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void print() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d\t", dis[i][j]);
		}
		puts("");
	}
}

int main() {
	flowr();
	print();
	return 0;
}
