//emaxx

#include <bits/stdc++.h>
using namespace std;

int n;
int l, r;

void naive() {
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int len = sqrt(n) + 1;
	vector<int> b(len);
	for(int i = 0; i < n; i++)
		b[i / len] += a[i];
	scanf("%d %d", &l, &r);
	int ans = 0;
	for(int i = l; i <= r; ) {
		if(i % len == 0 && i + len - 1 <= r) {//l is in pos of block's start and endofblock is before or equals to r
			ans += b[i / len];
			i += len;
		}
		else {
			ans += a[i];
			i++;
		}
	}
	printf("%d\n", ans);
}

void better() {
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int len = sqrt(n) + 1;
	vector<int> b(len);
	for(int i = 0; i < n; i++) {
		b[i / len] += a[i];
	}
	scanf("%d %d", &l, &r);
	int cl = l / len, cr = r / len;
	int ans = 0;
	if(cl == cr) {
		ans += b[cl];
	}
	else {
		for(int i = l, end = (cl + 1) * (len - 1); i <= end; i++)
			ans += a[i];
		for(int i = cl + 1; i < cr; i++)
			ans += b[i];
		for(int i = cr * len; i <= r; i++)
			ans += a[i];
	}
	printf("%d\n", ans);
}

int main() {
	freopen("in.txt", "r", stdin);
	naive();//many divisions, which is much slower than other operations.
	better();// getting the value of left tails and right tails before processing.
	return 0;
}
